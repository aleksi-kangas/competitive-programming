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

constexpr ll kMOD = 1e9 + 7;

void Solve() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> m(h, vector<char>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> m[i][j];
    }
  }

  vector<vector<int>> dp(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (m[i][j] == '#') {
        dp[i][j] = 0;
        continue;
      }
      if (i == 0 && j == 0) {
        dp[i][j] = 1;
        continue;
      }
      if (i == 0) {
        dp[i][j] = dp[i][j - 1];
        dp[i][j] %= kMOD;
        continue;
      }
      if (j == 0) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] %= kMOD;
        continue;
      }

      if (dp[i - 1][j] == 0 && dp[i][j - 1] == 0) {
        dp[i][j] = 0;
        continue;
      }

      if (dp[i - 1][j] == 0) {
        dp[i][j] = dp[i][j - 1];
        dp[i][j] %= kMOD;
        continue;
      }

      if (dp[i][j - 1] == 0) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] %= kMOD;
        continue;
      }

      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      dp[i][j] %= kMOD;
    }
  }

  cout << dp[h - 1][w - 1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solve();
}
