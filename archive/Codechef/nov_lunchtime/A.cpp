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
#define hmax priority_queue<ii>
#define hmin priority_queue<ii,vii,greater<ii>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1;

void solve(){
    int n,cnt=0;
    cin>>n;
    vi f(n),c(n);
    tr(e,f) cin>>e;
    tr(e,c) cin>>e;
    hmax a;
    unordered_map<int,int> m;
    fr(i,0,n){
        if(f[i]==0) continue;
        if(cnt+f[i]<=n){ 
            cnt+=f[i];
            a.push({c[i],f[i]});
            continue;
        }
        if(cnt<n){
            f[i]-=n-cnt;
            a.push({c[i],n-cnt});
            cnt=n;
        }
        int num=0;
        while(f[i]>0){
            ii e=a.top();
            if(e.F<=c[i]) break;
            a.pop();
            if(e.S>f[i]){
                a.push({e.F,e.S-f[i]});
                num+=f[i],f[i]=0;
            }
            else f[i]-=e.S,num+=e.S;
        }
        if(num>0) a.push({c[i],num});
    }
    int res=0;
    while(!a.empty()){
        ii e=a.top();
        a.pop();
        res+=e.F*e.S;
    }
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