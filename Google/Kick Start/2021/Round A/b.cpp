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
  int r, c;
  cin >> r >> c;

  vector<vector<int>> m(r, vector<int>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> m[i][j];
    }
  }

  int ans = 0;

  for (int flip_x : {0, 1}) {
    for (int flip_y : {0, 1}) {
      vector<vector<int>> left(r, vector<int>(c));
      vector<vector<int>> up(r, vector<int>(c));

      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (m[i][j] == 0) continue;
          if (i > 0) {
            up[i][j] = up[i - 1][j] + 1;
          } else {
            up[i][j] = 1;
          }
          if (j > 0) {
            left[i][j] = left[i][j - 1] + 1;
          } else {
            left[i][j] = 1;
          }
        }
      }

      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          int l = left[i][j];
          int u = up[i][j];

          if (m[i][j] == 0 || l == 1 || u == 1) continue;

          ans += max(min(l / 2, u) - 1, 0);
          ans += max(min(l, u / 2) - 1, 0);
        }
      }

      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c / 2; ++j) {
          swap(m[i][j], m[i][c - j - 1]);
        }
      }
    }
    for (int i = 0; i < r / 2; ++i) {
      for (int j = 0; j < c; ++j) {
        swap(m[i][j], m[r - i - 1][j]);
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
    int answer = Solve();
    cout << "Case #" << test_case << ": " << answer << endl;
  }
}