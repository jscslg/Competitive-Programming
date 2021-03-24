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
int MAX=1e5+1;

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n+1,-1);
    tr(e,a) cin>>e,b[e]=0;
    bool st=0,en=0;
    for(int i=0;i<n;){
        int e=a[i];
        if(i==0) st=1;
        while(i<n&&a[i]==e) i++;
        if(i==n) en=1;

        if(st&&en) b[e]=0;
        else if(st) b[e]++;
        else if(en&&b[e]!=0);
        else if(en) b[e]++;
        else if(b[e]==0) b[e]+=2;
        else b[e]++;

        st=0,en=0;
    }
    int res=n+1;
    tr(e,b){
        //cout<<e<<" ";
        if(e!=-1) res=min(res,e);
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