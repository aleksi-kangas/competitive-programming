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
  int n;
  cin >> n;
  string s;
  cin >> s;

  set<char> special_chars{'#', '@', '*', '&'};

  bool lower_case = false;
  bool upper_case = false;
  bool digit = false;
  bool special_char = false;

  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if ('a' <= int(c) && int(c) <= 'z') {
      lower_case = true;
    } else if ('A' <= int(c) && int(c) <= 'Z') {
      upper_case = true;
    } else if ('0' <= int(c) && int(c) <= '9') {
      digit = true;
    } else if (special_chars.count(c)) {
      special_char = true;
    }
  }

  if (!lower_case) {
    s.push_back('a');
  }
  if (!upper_case) {
    s.push_back('A');
  }
  if (!digit) {
    s.push_back('0');
  }
  if (!special_char) {
    s.push_back('#');
  }

  while (s.size() < 7) {
    s.push_back('a');
  }
  return s;
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
