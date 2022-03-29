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
  string s, p;
  cin >> s >> p;

  if (p.size() < s.size()) {
    return "IMPOSSIBLE";
  }

  size_t answer = 0;
  size_t i = 0;
  size_t j = 0;
  while (i < s.size() && j < p.size()) {
    if (s[i] == p[j]) {
      ++i;
      ++j;
    } else {
      ++answer;
      ++j;
    }
  }
  if (i == s.size()) {
    answer += p.size() - j;
    return to_string(answer);
  } else {
    return "IMPOSSIBLE";
  }
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
