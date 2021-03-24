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
#define hmax priority_queue<ii>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5;

void solve(){
    int n,m;
    cin>>n>>m;
    vi a(m,0);
    vii c(m);
    F0(i,n) {
        int e;cin>>e,e--;
        a[e]++;
    }
    F0(i,m) {
        int j;cin>>j;
        c[i]={j,a[i]};
    }
    int j=m-1,i=0,res=0;
    while(i<j){
        while(i<j && c[j].S){
            res+=c[i].F,i++,c[j].S--;
        }
        j--;
    }
    TR(e,c) res+=e.F*e.S;
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