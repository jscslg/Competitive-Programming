/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:(a))
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
int MAX=1e5;

void solve(){
    int n,l,r,res=0;
    cin>>n>>l>>r;
    vi a(n);
    vii f(n,{0,0});
    tr(e,a) cin>>e,e--;
    fr(i,0,l) f[a[i]].F++;
    fr(i,l,n) f[a[i]].S++;
    int x=0,y=0;
    fr(i,0,n){
        if(f[i].S<f[i].F) {
            int t=f[i].F-f[i].S;
            if(l<=r) x+=t;
            else if((l-r)/2<=t/2) {
                res+=(l-r)/2,t-=(l-r);
                l=r=n/2;
                x+=t;
            }
            else res+=t/2,x+=(t&1),l+=t/2,r-=t/2;
        }
        else if(f[i].S>f[i].F){
            int t=f[i].S-f[i].F;
            if(r<=l) y+=t;
            else if((r-l)/2<=t/2) {
                res+=(r-l)/2,t-=(r-l);
                l=r=n/2;
                y+=t;
            }
            else res+=t/2,y+=(t&1),r+=t/2,l-=t/2;
        }
    }
    //cout<<x<<"x"<<y<<" ";
    cout<<res+max(x,y)<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}