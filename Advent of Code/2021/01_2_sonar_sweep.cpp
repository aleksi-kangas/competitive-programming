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

vector<int> ReadDepths() {
  vector<int> depths;
  string s;
  while (getline(cin, s) && !s.empty()) {
    try {
      int a = stoi(s);
      depths.push_back(a);
    } catch (const invalid_argument &invalid_argument) {
      break;
    }
  }
  return depths;
}

int Solve() {
  vector<int> depths = ReadDepths();
  int count = 0;
  for (int i = 0; i < static_cast<int>(depths.size()) - 3; ++i) {
    int a = 0;
    int b = 0;
    for (int j = i; j <= i + 2; ++j) {
      a += depths[j];
      b += depths[j + 1];
    }
    if (b > a) {
      ++count;
    }
  }
  return count;
}

int main() {
  int count = Solve();
  cout << count << endl;
}
