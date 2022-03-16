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

// k + (k + 1) + (k + 2) + ... + (k + i - 1) = G
// (k + 1) + (k + 2) + ... + (k + i) = G
// i * ((k + 1) + (k + i)) / 2 = G
// i * (2k + i + 1) / 2 = G
// i * (2k + i + 1) = 2 * G

// Let d = (2k + i + 1)
// -> i * d = 2 * G

// Either i == odd && d == even, or vice versa

ll Solve() {
  ll g;
  cin >> g;

  ll g2 = g * 2;

  ll answer = 0;
  for (ll x = 1; x * x <= g2; ++x) {
    if (g2 % x != 0) {
      continue;
    }

    {  // Case 1
      ll d = g2 / x;

      ll k2 = d - x - 1;
      if (k2 % 2 == 0 && k2 / 2 >= 0) {
        ++answer;
      }
    }

    {  // Case 2
      ll d = g2 / (g2 / x);
      ll k2 = d - x - 1;
      if (k2 % 2 == 0 && k2 / 2 >= 0) {
        ++answer;
      }
    }
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
