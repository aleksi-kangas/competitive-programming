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

  int k = 1;

  vector<int> removed(n + 1);

  int skipped = 0;
  int count = 0;

  int i = 1;
  while (true) {
    if (removed[i] == 0) {
      if (count == n - 1) {
        cout << i;
        return;
      }
      ++skipped;
      if (skipped == k + 1) {
        removed[i] = 1;
        skipped = 0;
        ++count;
        cout << i << ' ';
      }
    }
    ++i;
    if (i > n) {
      i = 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
