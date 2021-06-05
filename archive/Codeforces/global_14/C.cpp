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
#define hmin priority_queue<ii,vii,greater<ii>>
#define MOD 1000000007
#define int ll
int MAX=1e5;

void solve(){
    int n,m,x;
    cin>>n>>m>>x;
    vi a(n),b(m,0),res(n);
    tr(e,a) cin>>e;
    hmin h;
    fr(i,0,m) h.push({0,i});
    fr(i,0,n){
        ii j=h.top();
        h.pop();
        b[j.S]+=a[i];
        res[i]=j.S;
        h.push({b[j.S],j.S});
    }

    cout<<"YES\n";
    tr(e,res) cout<<e+1<<" ";
    cout<<"\n";
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