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

int Solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int answer = 0;
  for (int i = 0; i < n - 1; ++i) {
    int min_idx = i;
    for (int j = i; j < n; ++j) {
      if (a[j] < a[min_idx]) {
        min_idx = j;
      }
    }
    reverse(a.begin() + i, a.begin() + min_idx + 1);
    answer += min_idx - i + 1;
  }

  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    int answer = Solve();
    cout << "Case #" << test_case << ": " << answer << endl;
  }
}
