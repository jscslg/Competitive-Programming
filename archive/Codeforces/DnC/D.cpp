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
    int n,x1,x2,ex;
    cin>>n;
    vvi a(2,vi(n));
    tr(i,a) tr(j,i) cin>>j;
    x1=a[0][0],x2=a[1][0],ex=0;
    fr(i,1,n){
        int t1=x1,t2=x2,t3=ex;
        x1=max(x2+a[0][i],ex+a[0][i]);
        x2=max(t1+a[1][i],ex+a[1][i]);
        ex=max(ex,max(t1,t2));
    }
    cout<<max(x1,x2)<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}