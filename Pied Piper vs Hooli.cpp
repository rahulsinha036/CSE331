#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n' 
int cse=1;

void solve(){
    bool wrong = false;
    int n,a,b,x,y,z;int cnt = 0;
    priority_queue <int> pq;
    cin >> n>>a>>b>>x>>y>>z;
    int t;
    for(int i =0; i<n; i++){
        cin >> t;
        pq.push(t);
    }
int hooli =z-b;

int days =hooli/y;

int pep = (days*x)+a;
int idx = 0;
while(pep<z){
int lime = pq.top();
    pq.pop();
    cnt ++;
    pep = pep+lime;
    lime = lime/2;
    if(lime/2 <=0){
        wrong = true;
        break;
    }
    pq.push(lime);

}
    if(wrong){
        cout << "RIP" << endl;
    }else{
    cout << cnt << endl;        
    }
}
int32_t main(){
    int tc=1;cin>>tc;
    while(tc--){
      //cout<<"Case #"<<cse++ <<":"<<" ";        
        solve();
    }
}
