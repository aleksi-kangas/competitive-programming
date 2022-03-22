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

string Solve() {
  string k;
  cin >> k;

  auto c = tolower(k.back());
  if (c == 'y') {
    return k + " is ruled by nobody.";
  }

  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  return k + " is ruled by " + (vowels.count(c) ? "Alice." : "Bob.");
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    string answer = Solve();
    cout << "Case #" << test_case << ": " << answer << endl;
  }
}
