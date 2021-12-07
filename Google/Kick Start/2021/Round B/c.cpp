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

/**
 * https://en.wikipedia.org/wiki/Primality_test
 * @param n
 * @return
 */
bool IsPrime(ll n) {
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  for (ll i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

ll Solve() {
  ll z;
  cin >> z;

  ll limit = (ll) sqrt(z);

  // Find the first prime number that's greater than sqrt(Z).
  ll above_limit = limit + 1;
  while (true) {
    if (IsPrime(above_limit)) {
      break;
    }
    ++above_limit;
  }

  // Find two greatest prime numbers that are less than or equal to sqrt(Z).
  ll a, b;  // b > a
  bool one_found = false;
  for (ll i = limit; i >= 0; --i) {
    if (IsPrime(i)) {
      if (!one_found) {
        b = i;
        one_found = true;
      } else {
        a = i;
        break;
      }
    }
  }

  if (b * above_limit <= z) {
    return b * above_limit;
  } else {
    return a * b;
  }
}

int main() {
  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    ll answer = Solve();
    cout << "Case #" << test_case << ": " << answer << endl;
  }
}
