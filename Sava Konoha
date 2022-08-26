#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ;
    cin>>t;
    
    while(t--) {
        int N, i,Z,temp;
        cin>>N>>Z;
        
        priority_queue<int> A;
        for(i=0;i<N;i++){
            cin>>temp;
            A.push(temp);
        }
        
        int hits=0;
        while(A.top()!=0 && Z>0){
            hits++;
            temp = A.top();
            Z-=temp;
            A.pop();
            A.push(temp/2);
        }
        
        if(Z>0)
            cout<<"Evacuate"<<endl;
        else
            cout<<hits<<endl;
    }
    return 0;
}
