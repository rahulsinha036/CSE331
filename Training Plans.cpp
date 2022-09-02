#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return b[i] < b[j];});
        double lo = 0, hi = 1e5;
        for(int k = 0; k < 40; ++k) {
            double mid = (lo + hi) / 2;
            vector<double> c(n); vector<int> d(n);
            for(int j = 0; j < n; ++j) c[j] = a[ord[j]] - mid, d[j] = b[ord[j]];
            int i = 0, ok = 0;
            priority_queue<double> q;
            double tot = 0;
            for(int j = 1; j <= n; ++j) {
                while(i < n && d[i] < j) {
                    q.push(c[i]);
                    ++i;
                }
                if(q.empty()) break;
                tot += q.top(); q.pop();
                if(tot > 0) {
                    ok = 1;
                    break;
                }
            }
            if(ok) lo = mid;
            else hi = mid;
        }
        cout << fixed << setprecision(10) << lo << '\n';
    }
}
