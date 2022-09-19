#include <bits/stdc++.h>

using namespace std;
typedef long long int LL;


int main()
{
	
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,q,k;
	cin>>n>>q;
	multiset<LL> s;
	multiset<LL> ::iterator it;
	LL x,y,z;
	LL sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
		s.insert(x);
	}
	LL ans[n+1];
	ans[0]=sum;
	for(int i=1;i<n;i++)
	{
		it=s.begin();
		x=*it;
		s.erase(it);
		it=s.end();
		it--;
		y=*it;
		s.erase(it);
		z=abs(x-y);
		sum-=(x+y);
		sum+=z;
		s.insert(z);
		ans[i]=sum;

	}
	while(q--)
	{
		cin>>k;
		cout<<ans[k]<<"\n";
	}
	return 0;
}
