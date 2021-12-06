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

  vector<pair<int, int>> movies;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    movies.emplace_back(a, b);
  }

  sort(movies.begin(), movies.end(), [](auto &left, auto &right) {
    return left.second < right.second;
  });

  int ans = 1;
  pair<int, int> previous = movies.front();
  for (int i = 1; i < n; ++i) {
    if (movies[i].first >= previous.second) {
      ++ans;
      previous = movies[i];
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solve();
}
