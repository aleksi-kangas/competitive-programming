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

ll Solve() {
  int r, c;
  cin >> r >> c;

  vector<vector<int>> m(r, vector<int>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> m[i][j];
    }
  }

  ll ans = 0;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i < r - 1) {
        int diff = m[i][j] - m[i + 1][j];
        if (diff > 1) {
          m[i + 1][j] += diff - 1;
          ans += diff - 1;
        }
      }
      if (j < c - 1) {
        int diff = m[i][j] - m[i][j + 1];
        if (diff > 1) {
          m[i][j + 1] += diff - 1;
          ans += diff - 1;
        }
      }
    }
  }

  for (int i = r - 1; i >= 0; --i) {
    for (int j = c - 1; j >= 0; --j) {
      if (i >= 1) {
        int diff = m[i][j] - m[i - 1][j];
        if (diff > 1) {
          m[i - 1][j] += diff - 1;
          ans += diff - 1;
        }
      }
      if (j >= 1) {
        int diff = m[i][j] - m[i][j - 1];
        if (diff > 1) {
          m[i][j - 1] += diff - 1;
          ans += diff - 1;
        }
      }
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
    ll answer = Solve();
    cout << "Case #" << test_case << ": " << answer << endl;
  }
}