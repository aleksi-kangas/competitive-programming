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
  int n, m;
  cin >> n >> m;

  map<int, int, greater<>> p;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++p[a];
  }

  for (int i = 0; i < m; ++i) {
    if (p.empty()) {
      cout << "-1" << '\n';
      continue;
    }

    int c;
    cin >> c;

    auto it = p.lower_bound(c);
    if (it != p.end()) {
      cout << it->first << '\n';
      --it->second;
      if (it->second == 0) {
        p.erase(it);
      }
    } else {
      cout << "-1" << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
