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

void Solve() {
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  vector<ll> dp(x + 1, INT_MAX);
  dp[0] = 0;

  for (int v = 0; v <= x; ++v) {
    for (int c : coins) {
      if (v - c >= 0) {
        dp[v] = min(dp[v], dp[v - c] + 1);
      }
    }
  }

  cout << (dp[x] != INT_MAX ? dp[x] : -1) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
