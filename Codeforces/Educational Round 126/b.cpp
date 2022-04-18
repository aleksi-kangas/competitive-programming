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

using namespace std;

using ll = long long;

void Solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    int answer = 15;
    for (int add = 0; add <= 15; ++add) {
      for (int multi = 0; multi <= 15; ++multi) {
        int p = 1 << multi;
        if ((p * (a[i] + add)) % 32768 == 0) {
          answer = min(answer, add + multi);
        }
      }
    }
    cout << answer << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solve();
}
