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

int Solve() {

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    int answer = Solve();
    cout << "Case #" << test_case << ": " << answer << '\n';
  }
}
