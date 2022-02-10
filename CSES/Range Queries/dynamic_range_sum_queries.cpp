#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

struct Range {
  int low;
  int high;
};

vector<ll> segment_tree;

ll QueryRangeSum(int node_idx, Range node, Range query) {
  if (query.low <= node.low && node.high <= query.high) {
    return segment_tree[node_idx];
  }
  if (node.high < query.low || query.high < node.low) {
    return 0;
  }
  int mid = node.low + (node.high - node.low) / 2;
  return QueryRangeSum(node_idx * 2, {node.low, mid}, query)
      + QueryRangeSum(node_idx * 2 + 1, {mid + 1, node.high}, query);
}

void UpdateSumTree(int idx, int value) {
  int m = static_cast<int>(segment_tree.size() / 2);
  segment_tree[m + idx] = value;

  for (int i = (m + idx) / 2; i >= 1; i /= 2) {
    segment_tree[i] = segment_tree[i * 2] + segment_tree[i * 2 + 1];
  }
}

void PerformQuery() {
  int type;
  cin >> type;
  switch (type) {
    case 1:  // Update
    {
      int k, u;
      cin >> k >> u;
      --k;
      UpdateSumTree(k, u);
      break;
    }
    case 2:  // Query
    {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      ll answer = QueryRangeSum(1, {0, static_cast<int>(segment_tree.size() / 2) - 1}, {a, b});
      cout << answer << '\n';
      break;
    }
    default:
      throw runtime_error("Unknown query type.");
  }
}

void Solve() {
  int n, q;
  cin >> n >> q;

  int m = n;
  while (__builtin_popcount(m) != 1) ++m;
  segment_tree.resize(2 * m);

  for (int i = 0; i < n; ++i) {
    cin >> segment_tree[m + i];
  }

  for (int i = m - 1; i >= 1; --i) {
    segment_tree[i] = segment_tree[2 * i] + segment_tree[2 * i + 1];
  }

  for (int i = 0; i < q; ++i) {
    PerformQuery();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
