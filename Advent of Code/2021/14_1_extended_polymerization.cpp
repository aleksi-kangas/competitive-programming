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
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

string ReadInitial() {
  string initial;
  getline(cin, initial);
  string discard;
  getline(cin, discard);
  return initial;
}

map<pair<char, char>, char> ReadRules() {
  map<pair<char, char>, char> rules;
  string s;
  while (getline(cin, s) && !s.empty()) {
    char a = s.front();
    char b = s[1];
    char c = s.back();
    rules.insert({{a, b}, c});
  }
  return rules;
}

int Solve() {
  string s = ReadInitial();
  map<pair<char, char>, char> rules = ReadRules();
  for (int step = 1; step <= 10; ++step) {
    string n;
    n.reserve(s.size());
    for (int i = 0; i < s.size() - 1; ++i) {
      char a = s[i];
      char b = s[i + 1];
      n.push_back(a);
      if (rules.contains({a, b})) {
        n.push_back(rules[{a, b}]);
      }
    }
    n.push_back(s.back());
    s = move(n);
  }

  map<char, int> freq;
  for (char c : s) {
    ++freq[c];
  }
  int maximum = numeric_limits<int>::min();
  int minimum = numeric_limits<int>::max();
  for (const auto &[c, f] : freq) {
    maximum = max(maximum, f);
    minimum = min(minimum, f);
  }
  return maximum - minimum;
}

int main() {
  int answer = Solve();
  cout << answer << endl;
}
