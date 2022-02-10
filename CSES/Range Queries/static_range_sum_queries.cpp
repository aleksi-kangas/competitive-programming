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

ll QueryRangeMinimum(int node_idx, Range node, Range query) {
  if (query.low <= node.low && node.high <= query.high) {
    return segment_tree[node_idx];
  }
  if (node.high < query.low || query.high < node.low) {
    return 0;
  }
  int mid = node.low + (node.high - node.low) / 2;
  return QueryRangeMinimum(node_idx * 2, {node.low, mid}, query)
      + QueryRangeMinimum(node_idx * 2 + 1, {mid + 1, node.high}, query);
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
    int low, high;
    cin >> low >> high;
    --low;
    --high;
    ll answer = QueryRangeMinimum(1, {0, m - 1}, {low, high});
    cout << answer << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
