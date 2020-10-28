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
    int n,a,b,c,x,y,z;
    cin>>n>>a>>b>>c>>x>>y>>z;
    int mx=0,mn=0;
    mx+=min(a,y)+min(b,z)+min(c,x);
    if(a>x+z) mn+=a-x-z;
    else if(b>x+y) mn+=b-x-y;
    else if(c>y+z) mn+=c-y-z;
    cout<<mn<<" "<<mx;
}

int main(){
    fast;
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}