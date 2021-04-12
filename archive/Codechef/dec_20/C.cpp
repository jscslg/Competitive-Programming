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
    int n,X,p=31;
    cin>>n>>X;
    vi a(n),index(p,0);
    tr(e,a) cin>>e;
    vvi h(p,vi());
    fr(i,0,p){
        fr(j,0,n) if(a[j]&(1<<i)) h[i].pb(j);
    }
    fr(i,0,n-1){
        frv(j,p-1,0){
            int x=1<<j,pos=index[j],sz=(int)h[j].size()-pos;
            if(sz==0||h[j][pos]!=i) continue;
            a[i]-=x,X--;
            if(sz>1) a[h[j][pos+1]]-=x,index[j]+=2;
            else a[n-1]+=x,index[j]++;
            // tr(e,a) cout<<e<<" ";
            // cout<<"\n";
            if(X==0) break;
        }
        if(X==0) break;
    }
    if(n==2&&X%2==1||X==1){
        a[n-2]++,a[n-1]^=1;
    }
    tr(e,a) cout<<e<<" ";
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