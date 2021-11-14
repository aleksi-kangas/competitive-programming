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

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  stack<pair<int, int>> stack;
  for (int i = 0; i < n; ++i) {
    while (!stack.empty() && stack.top().first >= a[i]) {
      stack.pop();
    }
    if (stack.empty()) {
      cout << 0 << ' ';
    } else {
      cout << stack.top().second << ' ';
    }
    stack.push({a[i], i + 1});
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}