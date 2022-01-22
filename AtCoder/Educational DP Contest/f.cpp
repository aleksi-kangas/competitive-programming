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
  string s, t;
  cin >> s >> t;

  int n = static_cast<int>(s.size());
  int m = static_cast<int>(t.size());

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {  // Diagonally
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {  // Left or up
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
  }

  string answer;
  answer.reserve(dp[n][m]);
  int i = n;
  int j = m;
  while (dp[i][j] != 0) {
    if (s[i - 1] == t[j - 1]) {  // Diagonally
      answer.push_back(s[i - 1]);
      --i;
      --j;
    } else if (dp[i][j - 1] > dp[i - 1][j]) { // Left
      --j;
    } else { // Up
      --i;
    }
  }

  reverse(answer.begin(), answer.end());
  cout << answer << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solve();
}
