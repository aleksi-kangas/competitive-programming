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

bool IsPalindrome(const string &s) {
  for (int i = 0; i < static_cast<int>(s.size()) / 2; ++i) {
    if (s[i] != s[s.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}

string Solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n < 5) {
    return "POSSIBLE";
  }

  vector<string> first_five;
  first_five.emplace_back("");
  for (int i = 0; i < 5; ++i) {
    if (s[i] == '0' || s[i] == '1') {
      for (auto &f : first_five) {
        f.push_back(s[i]);
      }
    } else {
      vector<string> additional = first_five;
      for (auto &f : first_five) {
        f.push_back('0');
      }
      for (auto &a : additional) {
        a.push_back('1');
        first_five.push_back(a);
      }
    }
  }

  set<string> previous_five;
  for (auto &f : first_five) {
    if (!IsPalindrome(f)) {
      previous_five.insert(f);
    }
  }

  if (previous_five.empty()) {
    return "IMPOSSIBLE";
  }

  for (int i = 5; i < n; ++i) {
    set<string> current;
    if (s[i] == '0' || s[i] == '1') {
      for (auto &p : previous_five) {
        if (!IsPalindrome(p + s[i]) && !IsPalindrome(p.substr(1) + s[i])) {
          current.insert(p.substr(1) + s[i]);
        }
      }
    } else {
      for (auto &p : previous_five) {
        if (!IsPalindrome(p + '1') && !IsPalindrome(p.substr(1) + '1')) {
          current.insert(p.substr(1) + '1');
        }
        if (!IsPalindrome(p + '0') && !IsPalindrome(p.substr(1) + '0')) {
          current.insert(p.substr(1) + '0');
        }
      }
    }
    if (current.empty()) {
      return "IMPOSSIBLE";
    }
    previous_five = move(current);
  }

  return "POSSIBLE";
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
