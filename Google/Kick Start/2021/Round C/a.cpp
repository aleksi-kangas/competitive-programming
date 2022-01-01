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

ll efficient_power(ll base, ll exponent) {
  ll power = 1;
  while (exponent > 0) {
    if (exponent % 2 != 0) {
      power *= base;
      power %= kMOD;
    }
    base *= base;
    base %= kMOD;
    exponent >>= 1;
  }
  return power;
}

ll Solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  ll answer = 0;
  string palindrome = s;
  int mid = (n + 1) / 2;
  for (ll i = mid - 1; i >= 0; --i) {
    ll value = s[i] - 'a';
    if (value > k) {
      value = k;
    }
    ll count = value * efficient_power(k, (mid - 1) - i);
    answer += count;
    answer %= kMOD;
    // Need to manually check the edge case.
    // Otherwise, we would be off by one.
    palindrome[n - i - 1] = s[i];
  }
  if (palindrome < s) {
    ++answer;
    answer %= kMOD;
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    ll answer = Solve();
    cout << "Case #" << test_case << ": " << answer << endl;
  }
}
