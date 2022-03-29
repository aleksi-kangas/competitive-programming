#include <algorithm>
#include <bitset>
#include <cassert>
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

string Solve() {
  string s;
  cin >> s;

  int sum = 0;
  for (char c : s) {
    sum += c - '0';
  }
  int digit = sum % 9 != 0 ? 9 - sum % 9 : 0;
  if (digit == 0) {
    return s[0] + to_string(digit) + s.substr(1);
  }
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    if (digit < s[i] - '0') {
      return s.substr(0, i) + to_string(digit) + s.substr(i);
    }
  }
  return s + to_string(digit);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    string answer = Solve();
    cout << "Case #" << test_case << ": " << answer << '\n';
  }
}
