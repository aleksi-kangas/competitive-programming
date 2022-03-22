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

void Solve() {
  int n;
  cin >> n;

  int h = 0;
  priority_queue<int, vector<int>, greater<>> mpq;
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    if (c > h) {
      mpq.push(c);
    }
    while (!mpq.empty() && mpq.top() <= h) {
      mpq.pop();
    }
    if (static_cast<int>(mpq.size()) >= h + 1) {
      ++h;
    }
    while (!mpq.empty() && mpq.top() <= h) {
      mpq.pop();
    }
    cout << h << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    cout << "Case #" << test_case << ": ";
    Solve();
    cout << '\n';
  }
}
