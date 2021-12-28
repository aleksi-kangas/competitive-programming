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
    for (char c : s) {
      row.push_back(c - '0');
    }
    m.push_back(move(row));
  }
  return m;
}

void Flash(vector<vector<int>> &m, vector<vector<int>> &flashed, const pair<int, int> &position) {
  int a = static_cast<int>(m.size());
  int b = static_cast<int>(m[0].size());

  for (int i = position.first - 1; i <= position.first + 1; ++i) {
    for (int j = position.second - 1; j <= position.second + 1; ++j) {
      if ((i == position.first && j == position.second) || i < 0 || j < 0 || i == a || j == b) {
        continue;
      }
      ++m[i][j];
    }
  }

  for (int i = position.first - 1; i <= position.first + 1; ++i) {
    for (int j = position.second - 1; j <= position.second + 1; ++j) {
      if ((i == position.first && j == position.second) || i < 0 || j < 0 || i == a || j == b) {
        continue;
      }
      if (m[i][j] > 9 && flashed[i][j] == 0) {
        flashed[i][j] = 1;
        Flash(m, flashed, {i, j});
      }
    }
  }
}

int Solve() {
  int flashes = 0;
  vector<vector<int>> m = ParseInput();
  int a = static_cast<int>(m.size());
  int b = static_cast<int>(m[0].size());
  for (int s = 1; s <= 100; ++s) {
    // Increase all by one.
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        ++m[i][j];
      }
    }

    // Flash if needed.
    vector<vector<int>> flashed(a, vector<int>(b, 0));
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if (m[i][j] > 9 && flashed[i][j] == 0) {
          flashed[i][j] = 1;
          Flash(m, flashed, {i, j});
        }
      }
    }

    // Reset flashed to zero.
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if (flashed[i][j] == 1) {
          ++flashes;
          m[i][j] = 0;
        }
      }
    }
  }
  return flashes;
}

int main() {
  int flashes = Solve();
  cout << flashes << endl;
}
