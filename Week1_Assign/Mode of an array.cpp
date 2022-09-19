#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tc, cs = 1;

void test_cases() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  priority_queue<pair<int, int>> pq;
  for (auto p: mp) {
    if (p.first != k) pq.push({p.second, p.first});
  }
  int cnt = mp[k], ans = 0;
  while (!pq.empty()) {
    auto u = pq.top();
    pq.pop();
    int cur_cnt = u.first;
    if (cur_cnt < cnt) break;
    cnt++;
    cur_cnt--;
    ans++;
    if (cur_cnt) pq.push({cur_cnt, u.second});
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    test_cases();
  }
}
