#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);i++)
#define f_(i,a,b) for(ll i=(a);i>=(b);i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> w(n);
        for(auto& a:w) cin>>a;
        sort(w.begin(),w.end());
        int max=0;
        f(k,0,(2*n+1)){
            int i=0,j=n-1,sum=0;
            while(j>i){
                if(w[i]+w[j]==k) sum++,i++,j--;
                else if(w[i]+w[j]<k) i++;
                else j--;
            }
            if(sum>max) max=sum;
        }
        cout<<max<<endl;
    }
    return 0;
}