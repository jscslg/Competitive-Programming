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
    int n,s=0,x=0;
    cin>>n;
    vi a(n),pre(n,0),suf(n,0);
    tr(e,a) cin>>e;
    pre[0]=a[0],suf[n-1]=a[n-1];
    fr(i,1,n) pre[i]=pre[i-1]^a[i];
    frv(i,n-2,0) suf[i]=suf[i+1]^a[i];
    bool f=0;
    fr(i,0,n-1) if(pre[i]==suf[i+1]) f=1;
    fr(i,0,n-2) fr(j,i,n-1) if(pre[i]==(pre[j]^pre[i]) && pre[i]==suf[j+1]) f=1;
    cout<<(f?"YES\n":"NO\n");
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