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
        vector<ll> a(n),b(n);
        ll m1=1e+10,m2=1e+10;
        for(auto& i:a) {
            cin>>i;
            if(i<m1) m1=i;
        }
        for(auto& i:b) {
            cin>>i;
            if(i<m2) m2=i;
        }
        ll sum=0;
        f(i,0,n){
            ll c=a[i]-m1,d=b[i]-m2;
            sum+=(c>d?c:d);
        }
        cout<<sum<<endl;
    }
    return 0;
}