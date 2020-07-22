#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()  
{  
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,m,res=-1;
        cin>>n>>m;
        vector<ll> x(n,0),y(m,0);
        for(auto& a:x) cin>>a;
        for(auto& a:y) cin>>a;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(x[i]==y[j]) {
                    res=x[i];
                    break;
                }
            }
            if(res!=-1) break;
        }
        if(res==-1) cout<<"NO"<<endl;
        else cout<<"YES\n"<<1<<" "<<res<<endl;
    }
    return 0;  
}  