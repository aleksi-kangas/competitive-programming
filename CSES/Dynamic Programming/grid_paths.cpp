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
  int n;
  cin >> n;

  vector<vector<char>> g(n, vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> g[i][j];
    }
  }

  if (g[0][0] == '*') {
    cout << 0 << endl;
    return;
  }

  vector<vector<int>> dp(n, vector<int>(n));
  dp[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = (g[i][0] != '*') ? dp[i - 1][0] : 0;
    dp[0][i] = (g[0][i] != '*') ? dp[0][i - 1] : 0;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (g[i][j] != '*') {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        dp[i][j] %= kMOD;
      }
    }
  }

  cout << dp[n - 1][n - 1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
