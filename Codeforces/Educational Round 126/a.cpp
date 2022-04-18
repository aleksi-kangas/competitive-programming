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

void Solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  ll answer = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) {
      swap(a[i], b[i]);
    }
    if (i > 0) {
      answer += abs(a[i] - a[i - 1]);
      answer += abs(b[i] - b[i - 1]);
    }
  }

  cout << answer << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  while (test_cases--) {
    Solve();
  }
}
