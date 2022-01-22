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
  int n;
  cin >> n;

  vector<vector<int>> dp(n, vector<int>(3));

  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (i == 0) {
      dp[i][0] = a;
      dp[i][1] = b;
      dp[i][2] = c;
      continue;
    }
    dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
  }

  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solve();
}
