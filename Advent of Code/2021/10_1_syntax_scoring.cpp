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

vector<string> ParseInput() {
  vector<string> lines;
  string s;
  while (getline(cin, s) && !s.empty()) {
    lines.push_back(move(s));
  }
  return lines;
}

int Solve() {
  array<int, 4> errors{0, 0, 0, 0};
  array<int, 4> scores{3, 57, 1197, 25137};

  vector<string> lines = ParseInput();
  map<char, char> corresponding = {{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
  set<char> opening{'(', '[', '{', '<'};
  set<char> closing{')', ']', '}', '>'};
  for (string &line : lines) {
    stack<char> s;
    for (char c : line) {
      if (opening.contains(c)) {
        s.push(c);
      } else if (closing.contains(c)) {
        if (!s.empty() && s.top() == corresponding[c]) {
          s.pop();
        } else {
          switch (c) {
            case ')':
              ++errors[0];
              break;
            case ']':
              ++errors[1];
              break;
            case '}':
              ++errors[2];
              break;
            case '>':
              ++errors[3];
              break;
            default:
              break;
          }
          break;  // for c in line
        }
      }
    }
  }
  int error_score = 0;
  for (int i = 0; i < 4; ++i) {
    error_score += errors[i] * scores[i];
  }
  return error_score;
}

int main() {
  int error_score = Solve();
  cout << error_score << endl;
}
