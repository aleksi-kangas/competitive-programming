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

template<typename T>
void max_self(T &a, T b) {
  a = max(a, b);
}

int Solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> left(n);
  {
    left[0] = 1;
    left[1] = 2;
    ll diff = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
      if (a[i] - a[i - 1] == diff) {
        left[i] = left[i - 1] + 1;
      } else {
        left[i] = 2;
        diff = a[i] - a[i - 1];
      }
    }
  }

  vector<int> right(n);
  {
    right[n - 1] = 1;
    right[n - 2] = 2;
    ll diff = a[n - 2] - a[n - 1];
    for (int i = n - 3; i >= 0; --i) {
      if (a[i] - a[i + 1] == diff) {
        right[i] = right[i + 1] + 1;
      } else {
        right[i] = 2;
        diff = a[i] - a[i + 1];
      }
    }
  }

  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {  // 1 0 0 0 0 0 0 0 0 0
      max_self(ans, max(right[i], right[i + 1] + 1));
      continue;
    }
    if (i == n - 1) {  // 0 0 0 0 0 0 0 0 0 1
      max_self(ans, max(left[i], left[i - 1] + 1));
      continue;
    }
    if (i == 1) { // 0 1 0 0 0 0 0 0 0 0
      if (i + 2 < n && right[i + 1] >= 2) {
        ll diff = a[i + 2] - a[i + 1];
        if (a[i - 1] == a[i + 1] - diff * 2) {
          max_self(ans, right[i + 1] + 2);
        }
      }
    } else if (i == n - 2) {  // 0 0 0 0 0 0 0 0 1 0
      if (i - 2 >= 0 && left[i - 1] >= 2) {
        ll diff = a[i - 1] - a[i - 2];
        if (a[i + 1] == a[i - 1] + diff * 2) {
          max_self(ans, left[i - 1] + 2);
        }
      }
    } else {  // i > 1 && i < n - 2
      if ((a[i - 1] + a[i + 1]) % 2 == 0) {
        ll mid = a[i - 1] + (a[i + 1] - a[i - 1]) / 2;
        ll diff = mid - a[i - 1];
        ll before_diff = a[i - 1] - a[i - 2];
        ll after_diff = a[i + 2] - a[i + 1];
        if (diff == before_diff && diff == after_diff) {
          max_self(ans, left[i - 1] + right[i + 1] + 1);
        } else if (diff == before_diff) {
          // 0 0 X X 1 X 0 0 0 0
          max_self(ans, left[i - 1] + 2);
        } else if (diff == after_diff) {
          // 0 0 0 X 1 X X 0 0 0
          max_self(ans, right[i + 1] + 2);
        }
      }
    }
    max_self(ans, max(left[i], right[i]));
    max_self(ans, max(left[i - 1] + 1, right[i + 1] + 1));
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_cases;
  cin >> test_cases;

  for (int test_case = 1; test_case <= test_cases; ++test_case) {
    int answer = Solve();
    cout << "Case #" << test_case << ": " << answer << endl;
  }
}
