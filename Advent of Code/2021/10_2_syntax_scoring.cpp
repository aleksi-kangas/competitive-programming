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

ll Solve() {
  vector<string> lines = ParseInput();

  set<char> opening{'(', '[', '{', '<'};
  set<char> closing{')', ']', '}', '>'};
  map<char, char> corresponding = {{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};

  vector<ll> incompleteness_scores;

  for (string &line : lines) {
    stack<char> s;
    bool corrupt_line = false;
    for (char c : line) {
      if (opening.contains(c)) {
        s.push(c);
      } else if (closing.contains(c)) {
        if (!s.empty() && s.top() == corresponding[c]) {
          s.pop();
        } else {
          corrupt_line = true;
          break;
        }
      }
    }

    if (corrupt_line) {
      continue;
    }

    // Incompleteness penalties.
    ll score = 0;
    while (!s.empty()) {
      score *= 5;
      switch (s.top()) {
        case '(':
          score += 1;
          break;
        case '[':
          score += 2;
          break;
        case '{':
          score += 3;
          break;
        case '<':
          score += 4;
          break;
        default:
          break;
      }
      s.pop();
    }
    incompleteness_scores.push_back(score);
  }

  sort(incompleteness_scores.begin(), incompleteness_scores.end());
  return incompleteness_scores[incompleteness_scores.size() / 2];
}

int main() {
  ll error_score = Solve();
  cout << error_score << endl;
}
