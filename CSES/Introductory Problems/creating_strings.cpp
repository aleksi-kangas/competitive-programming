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
 * Iteratively calculate factorial of n.
 * @param n positive integer
 * @return
 */
int Factorial(int n) {
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= i;
  }
  return ans;
}

void Solve() {
  string s;
  cin >> s;

  sort(s.begin(), s.end());

  map<char, int> freq;
  for (char &c : s) {
    ++freq[c];
  }

  int possible_strings = Factorial(s.size());
  for (const auto &[c, f] : freq) {
    possible_strings /= Factorial(f);
  }

  cout << possible_strings << '\n';

  while (true) {
    cout << s << '\n';
    if (!next_permutation(s.begin(), s.end())) {
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
