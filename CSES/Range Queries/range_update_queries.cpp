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

ll RangeUpdate(int node_idx, Range node, Range query, int new_value) {
  if (query.low <= node.low && node.high <= query.high) {
    segment_tree[node_idx] += new_value;
    return segment_tree[node_idx];
  }
  if (node.high < query.low || query.high < node.low) {
    return 0;
  }
  int mid = node.low + (node.high - node.low) / 2;
  return segment_tree[node_idx]
      + RangeUpdate(2 * node_idx, {node.low, mid}, query, new_value)
      + RangeUpdate(2 * node_idx + 1, {mid + 1, node.high}, query, new_value);
}

void PerformQuery() {
  int type;
  cin >> type;
  switch (type) {
    case 1:  // Update
    {
      int a, b, u;
      cin >> a >> b >> u;
      --a;
      --b;
      RangeUpdate(1, {0, static_cast<int>(segment_tree.size() / 2) - 1}, {a, b}, u);
      break;
    }
    case 2:  // Query
    {
      int k;
      cin >> k;
      --k;
      ll answer = RangeUpdate(1, {0, static_cast<int>(segment_tree.size() / 2) - 1}, {k, k}, 0);
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

  for (int i = 0; i < q; ++i) {
    PerformQuery();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
