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

constexpr int kMOD = 1e9 + 7;

void Solve() {
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  vector<int> dp(x + 1);
  dp[0] = 1;
  for (int v = 1; v <= x; ++v) {
    for (int c : coins) {
      if (v - c >= 0) {
        dp[v] += dp[v - c];
        dp[v] %= kMOD;
      }
    }
  }

  cout << dp[x] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
