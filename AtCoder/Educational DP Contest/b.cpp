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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= max(0, i - k); --j) {
      dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
    }
  }

  cout << dp[n - 1] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solve();
}
