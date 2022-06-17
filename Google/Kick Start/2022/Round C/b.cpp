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

vector<int> Solve() {
  int n, x, y;
  cin >> n >> x >> y;

  int s = n * (n + 1) / 2;
  if (s % (x + y) != 0) {
    return {};
  }

  vector<int> alan;
  int alan_sum = x * (s / (x + y));
  for (int i = n; i > 0; --i) {
    if (i <= alan_sum) {  // Can take
      alan.push_back(i);
      alan_sum -= i;
    }
  }
  assert(alan_sum == 0);
  return alan;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    vector<int> answer = Solve();
    cout << "Case #" << test_case << ": " << (answer.empty() ? "IMPOSSIBLE" : "POSSIBLE") << '\n';
    if (!answer.empty()) {
      cout << answer.size() << '\n';
      for (int x : answer) {
        cout << x << " ";
      }
      cout << '\n';
    }
  }
}
