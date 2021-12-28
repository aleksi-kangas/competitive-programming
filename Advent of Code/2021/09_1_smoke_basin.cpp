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

vector<vector<int>> ParseInput() {
  vector<vector<int>> m;
  string s;
  while (getline(cin, s) && !s.empty()) {
    vector<int> row;
    row.reserve(s.size());
    for (char c : s) {
      row.push_back(c - '0');
    }
    m.push_back(move(row));
  }
  return m;
}

int Solve() {
  vector<vector<int>> heights = ParseInput();
  int n = static_cast<int>(heights.size());
  int m = static_cast<int>(heights[0].size());

  vector<vector<int>> down(n, vector<int>(m, 0));
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      if (heights[i][j] >= heights[i + 1][j]) {
        down[i][j] = down[i + 1][j] + 1;
      }
    }
  }

  vector<vector<int>> up(n, vector<int>(m, 0));
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (heights[i][j] >= heights[i - 1][j]) {
        up[i][j] = up[i - 1][j] + 1;
      }
    }
  }

  vector<vector<int>> left(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (heights[i][j] >= heights[i][j - 1]) {
        left[i][j] = left[i][j - 1] + 1;
      }
    }
  }

  vector<vector<int>> right(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = m - 2; j >= 0; --j) {
      if (heights[i][j] >= heights[i][j + 1]) {
        right[i][j] = right[i][j + 1] + 1;
      }
    }
  }

  int risk_sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (down[i][j] == 0 && up[i][j] == 0 && left[i][j] == 0 && right[i][j] == 0) {
        risk_sum += heights[i][j] + 1;
      }
    }
  }
  return risk_sum;
}

int main() {
  int risk_sum = Solve();
  cout << risk_sum << endl;
}
