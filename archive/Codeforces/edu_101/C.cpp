/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1;

void solve(){
    int n,k;
    cin>>n>>k;
    vi h(n);
    tr(e,h) cin>>e;
    int x=max(0ll,h[0]-k+1),y=h[0]+k-1;
    fr(i,1,n-1){
        int a=h[i],b=h[i]+k-1;
        //cout<<x<<" "<<y<<" x "<<a<<" "<<b<<"\n";
        if(b<x||a>y){
            cout<<"NO\n";
            return;
        }
        x=max(0ll,max(x,a)-k+1),y=min(b,y)+k-1;
    }
    int a=h[n-1],b=h[n-1];
    //cout<<x<<" "<<y<<" x "<<a<<" "<<b<<"\n";
    if(b<x||a>y){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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