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
  string s, previous;
  int count = 0;
  while (getline(cin, s) && !s.empty()) {
    if (previous.empty()) {
      previous = move(s);
      continue;
    }

    try {
      int a = stoi(previous);
      int b = stoi(s);
      if (b > a) {
        ++count;
      }
    } catch (const invalid_argument &invalid_argument) {
      continue;
    }
    previous = move(s);
  }
  return count;
}

int main() {
  int count = Solve();
  cout << count << endl;
}
