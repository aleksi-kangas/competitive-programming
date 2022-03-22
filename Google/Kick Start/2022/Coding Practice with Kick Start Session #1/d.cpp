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

/**
 * Simply an implementation following the strategy from the editorial.
 */

using namespace std;

using ll = long long;

enum class HexType {
  kEmpty,
  kBlue,
  kRed,
};

pair<int, int> ForwardHex(const pair<int, int> &reference, const pair<int, int> &neighbor, bool clock_wise) {
  static constexpr pair<int, int> kDirections[] = {
      {-1, 0},  // N
      {-1, 1},  // NE
      {0, 1},  // E
      {1, 0},  // S
      {1, -1},  // SW
      {0, -1},  // W
  };

  pair<int, int> neighbor_direction = {neighbor.first - reference.first, neighbor.second - reference.second};
  for (int i = 0; i < 6; ++i) {
    if (kDirections[i] == neighbor_direction) {
      int new_index = [&]() {
        if (clock_wise) {
          return (i + 1) % 6;
        } else {
          return (i - 1 + 6) % 6;
        }
      }();
      pair<int, int> new_direction = kDirections[new_index];
      return {reference.first + new_direction.first, reference.second + new_direction.second};
    }
  }
  assert(false);
  return {0, 0};
}

optional<set<pair<int, int>>> NorthPath(const vector<vector<HexType>> &board) {
  int n = static_cast<int>(board.size());
  // Start from NE
  pair<int, int> left = {0, n - 1};  // Reference
  pair<int, int> right = {0, n - 2};  // Neighbor

  set<pair<int, int>> path;

  while (left.second > 0) {
    path.insert(left);
    pair<int, int> forward_hex = ForwardHex(left, right, false);
    if (board[forward_hex.first][forward_hex.second] == HexType::kBlue) {
      left = forward_hex;  // Go right
    } else {
      right = forward_hex;  // Go left
    }
    if (right.first == n - 1) {
      return nullopt;
    }
  }

  return path;
}

optional<set<pair<int, int>>> SouthPath(const vector<vector<HexType>> &board) {
  int n = static_cast<int>(board.size());
  // Start from SW
  pair<int, int> left = {n - 1, 0};  // Reference
  pair<int, int> right = {n - 1, 1};  // Neighbor

  set<pair<int, int>> path;

  while (left.second < n - 1) {
    path.insert(left);
    pair<int, int> forward_hex = ForwardHex(left, right, false);
    if (board[forward_hex.first][forward_hex.second] == HexType::kBlue) {
      left = forward_hex;  // Go right
    } else {
      right = forward_hex;  // Go left
    }
    if (right.first == 0) {
      return nullopt;
    }
  }

  return path;
}

optional<set<pair<int, int>>> WestPath(const vector<vector<HexType>> &board) {
  int n = static_cast<int>(board.size());
  // Start from SW
  pair<int, int> left = {n - 1, 0};  // Neighbor
  pair<int, int> right = {n - 1, 1};  // Reference

  set<pair<int, int>> path;

  while (right.first > 0) {
    path.insert(right);
    pair<int, int> forward_hex = ForwardHex(right, left, true);
    if (board[forward_hex.first][forward_hex.second] == HexType::kRed) {
      right = forward_hex;  // Go left
    } else {
      left = forward_hex;  // Go right
    }
    if (left.second == n - 1) {
      return nullopt;
    }
  }

  return path;
}

optional<set<pair<int, int>>> EastPath(const vector<vector<HexType>> &board) {
  int n = static_cast<int>(board.size());
  // Start from NE
  pair<int, int> left = {0, n - 1};  // Neighbor
  pair<int, int> right = {0, n - 2};  // Reference

  set<pair<int, int>> path;

  while (right.first < n - 1) {
    path.insert(right);
    pair<int, int> forward_hex = ForwardHex(right, left, true);
    if (board[forward_hex.first][forward_hex.second] == HexType::kRed) {
      right = forward_hex;  // Go left
    } else {
      left = forward_hex;  // Go right
    }
    if (left.second == 0) {
      return nullopt;
    }
  }

  return path;
}

string Solve() {
  int n;
  cin >> n;

  if (n == 1) {
    char c;
    cin >> c;
    switch (c) {
      case 'B':
        return "Blue wins";
      case 'R':
        return "Red wins";
      case '.':
        return "Nobody wins";
      default:
        assert(false);
    }
  }

  int m = n + 2;

  vector<vector<HexType>> board(m, vector<HexType>(m));
  for (int i = 0; i < m; ++i) {
    board[0][i] = HexType::kRed;
    board[m - 1][i] = HexType::kRed;
  }
  for (int i = 0; i < m; ++i) {
    board[i][0] = HexType::kBlue;
    board[i][m - 1] = HexType::kBlue;
  }
  int counter = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c;
      cin >> c;
      switch (c) {
        case 'B':
          board[i][j] = HexType::kBlue;
          ++counter;
          break;
        case 'R':
          board[i][j] = HexType::kRed;
          --counter;
          break;
        case '.':
          board[i][j] = HexType::kEmpty;
          break;
        default:
          assert(false);
      }
    }
  }

  if (counter < -1 || 1 < counter) {
    return "Impossible";
  }

  auto north_path = NorthPath(board);
  if (north_path) {
    auto south_path = SouthPath(board);
    assert(south_path);
    for (const auto &hex : *north_path) {
      if (south_path->count(hex) && counter >= 0) {
        return "Blue wins";
      }
    }
    return "Impossible";
  }

  auto west_path = WestPath(board);
  if (west_path) {
    auto east_path = EastPath(board);
    assert(east_path);
    for (const auto &hex : *west_path) {
      if (east_path->count(hex) && counter <= 0) {
        return "Red wins";
      }
    }
    return "Impossible";
  }

  return "Nobody wins";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    string answer = Solve();
    cout << "Case #" << test_case << ": " << answer << '\n';
  }
}
