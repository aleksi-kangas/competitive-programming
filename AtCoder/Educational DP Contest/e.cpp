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

constexpr ll INF = 1e18 + 10;

void Solve() {
  int n, W;
  cin >> n >> W;

  vector<int> w(n);
  vector<int> v(n);
  int total_value = 0;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
    total_value += v[i];
  }

  // Keep track of the minimum weight that achieves one specific value.
  vector<ll> dp(total_value + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {  // For each item
    for (int j = total_value - v[i]; j >= 0; --j) {  // For each smaller value
      // Take the item if the cumulative weight is smaller than previously computed.
      dp[v[i] + j] = min(dp[v[i] + j], dp[j] + w[i]);
    }
  }

  ll answer = 0;
  for (ll i = 0; i <= total_value; ++i) {
    if (dp[i] <= W) {
      answer = max(answer, i);
    }
  }

  cout << answer << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solve();
}
