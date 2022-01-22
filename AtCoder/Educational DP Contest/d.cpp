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
  int n, W;
  cin >> n >> W;

  vector<int> w(n);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }

  // Keep track of the maximum value one can achieve with one specific weight.
  vector<ll> dp(W + 1);
  for (int i = 0; i < n; ++i) {  // For each item
    for (int j = W; j >= 0; --j) {  // For each weight
      if (w[i] <= j) {  // Can we take?
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
    }
  }

  cout << dp[W] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solve();
}
