#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int  t;
    cin >> t;
    while(t--)
    {
        int  n,Q;
        cin >> n >> Q;
        ll a[n],b[n];
        for(int i = 0; i<n; i++)
            cin >> a[i];
        for(int  i = 0; i<n; i++)
            cin >> b[i];
        sort(a,a+n);
        sort(b,b+n);
        priority_queue <ll> pq;
        for(ll i = 0; i<n; i++)
        {
            for(ll j = 0; j<n; j++)
            {
                if(pq.size() <= 10000)
                    pq.push(a[i] + b[j]);
                else if(a[i] + b[j] < pq.top())
                {
                    pq.pop();
                    pq.push(a[i] + b[j]);
                }
                else
                    break;
            }
        }

        vector <ll> ans;
        while(!pq.empty())
        {
            ans.emplace_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());

        while(Q--)
        {
            int  q;
            cin >> q;
            cout << ans[q-1] <<endl;
        }
    }
	return 0;
}
