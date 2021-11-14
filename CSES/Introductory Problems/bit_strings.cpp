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
  // Basically the question is: How many integers can we represent with n bits?
  // Just need to take the modulo.

  constexpr int kModulo = 1e9 + 7;

  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    ans *= 2;
    ans %= kModulo;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}