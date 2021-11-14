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
  ll r, c;
  cin >> r >> c;

  ll ans;

  if (r == c) {
    ans = r * r - r + 1;
  } else if (r < c) {
    if (c % 2 == 0) {
      ans = c * c - c - c + r + 1;
    } else  {
      ans = c * c - r + 1;
    }
  } else  {
    if (r % 2 == 0) {
      ans = r * r - c + 1;
    } else  {
      ans = r * r - r - r + c + 1;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  while (test_cases--) {
    Solve();
  }
}