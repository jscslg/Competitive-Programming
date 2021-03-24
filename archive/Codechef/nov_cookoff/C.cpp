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
//#define int ll
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
int MAX=1e6+1;
vi pr(MAX,1);

void solve(){
    int k,x;
    cin>>k>>x;
    vi p;
    int t=x;
    while(pr[t]!=1) p.pb(pr[t]),t/=pr[t];
    if(t>1) p.pb(t);
    int n=p.size();
    if(k>=n){
        int s=0;
        tr(e,p) s+=e;
        s+=k-n;
        cout<<s<<"\n";
    }
    else{
        vvi dp(k,vi(n));
        
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=2;i*i<=MAX;i++){
        if(pr[i]==1){
            for(int j=i*i;j<=MAX;j+=i) if(pr[j]==1) pr[j]=i;
        }
    }
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}