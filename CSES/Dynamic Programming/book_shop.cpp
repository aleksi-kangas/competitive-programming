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

  vector<int> prices(n);
  for (int i = 0; i < n; ++i) {
    cin >> prices[i];
  }

  vector<int> pages(n);
  for (int i = 0; i < n; ++i) {
    cin >> pages[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(x + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      int price = prices[i - 1];
      int page = pages[i - 1];
      if (j - price >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price] + page);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[n][x] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
