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

vector<int> Solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> ans(n);
  ans[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] - 'A' > s[i - 1] - 'A') {
      ans[i] = ans[i - 1] + 1;
    } else {
      ans[i] = 1;
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    vector<int> answer = Solve();
    cout << "Case #" << test_case << ": ";
    for (int x: answer) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}
