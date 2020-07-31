#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);i++)
#define f_(i,a,b) for(ll i=(a);i>=(b);i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        ll m=(n+3)/4;
        f(i,0,n-m) cout<<9;
        f(i,0,m) cout<<8;
        cout<<endl;
    }
    return 0;
}