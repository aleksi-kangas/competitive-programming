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

  int answer = 0;

  while (n > 0) {
    int m = n;
    int max_digit = 0;
    while (m != 0) {
      int digit = m % 10;
      max_digit = max(max_digit, digit);
      m /= 10;
    }
    n -= max_digit;
    ++answer;
  }

  cout << answer << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
