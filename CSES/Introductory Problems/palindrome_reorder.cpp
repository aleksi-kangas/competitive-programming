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

void Solve() {
  string s;
  cin >> s;
  int n = (int) s.size();

  map<char, int> freq;
  for (int i = 0; i < n; ++i) {
    ++freq[s[i]];
  }

  int odds = 0;
  char odd_char;
  for (const auto &[c, f] : freq) {
    if (f % 2 != 0) {
      ++odds;
      odd_char = c;
      if (odds > 1) {
        cout << "NO SOLUTION" << endl;
        return;
      }
    }
  }

  string prefix;
  for (const auto &[c, f] : freq) {
    if (f % 2 == 0) {
      // Use half.
      for (int i = 0; i < f / 2; ++i) {
        prefix.push_back(c);
      }
    }
  }

  string middle;
  // Use odd chars.
  for (int i = 0; i < freq[odd_char]; ++i) {
    middle.push_back(odd_char);
  }

  string suffix = prefix;  // Make a copy.
  reverse(suffix.begin(), suffix.end());

  cout << (prefix + middle + suffix) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}