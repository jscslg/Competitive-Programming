#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

void solve(){
    ll n,a,b;
    cin>>n;
    a=sqrt(n),b=(n-1)/a+1;
    cout<<a+b-2<<endl;
}

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}