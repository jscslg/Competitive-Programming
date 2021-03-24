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
#define int ll
#define TR(i,a) for(auto& i:a)
#define F0(i,n) for(int i=0;i<(n);++i)
#define F1(i,n) for(int i=1;i<=(n);++i)
#define FO(i,a,b) for(int i=(a);i<(b);++i)
#define FR(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5;

void solve(){
    int n,x,res=0;
    cin>>n>>x;
    vii a(n);
    TR(e,a) {
        int j;cin>>j;
        e={j,1};
    }
    int i=0;
    while(i<a.size()){
        ii e=a[i++];
        if(e.F%x!=0) break;
        a.pb({e.F/x,e.S*x});
        //cout<<res<<" ";
    }
    i=0;
    while(i<a.size()) res+=a[i].F*a[i].S,i++;
    //TR(e,a) cout<<e.F<<"x"<<e.S<<" ";
    cout<<res<<"\n";
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