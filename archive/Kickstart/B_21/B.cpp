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
#define iii pair<ii,int>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
//#define int ll
int MAX=1e5;

void solve(){
    int n,res=0;
    cin>>n;
    vi a(n);
    tr(e,a) cin>>e;
    int i=1;
    vector<iii> s;
    while(i<n){
        int d=a[i]-a[i-1],j=i-1;
        while(i<n && a[i]-a[i-1]==d) i++;
        s.pb({{j,i-1},d}),res=max(res,i-j);
    }
    int m=s.size();
    fr(j,0,m){
        if(j<m-3 && s[j+1].F.S==s[j+2].F.F && s[j+3].S==s[j].S && s[j+3].F.F-s[j].F.S==2 && a[s[j+3].F.F]-a[s[j].F.S]==2*s[j].S) 
            res=max(res,s[j].F.S-s[j].F.F+s[j+3].F.S-s[j+3].F.F+3);
        if(j<m-1) {
            int en=s[j].F.S+2,num=s[j].F.S-s[j].F.F+2;
            if(en<n && a[en]-a[en-2]==s[j].S*2) num++;
            res=max(res,num);
        }
        if(j>0){
            int en=s[j].F.F-2,num=s[j].F.S-s[j].F.F+2;
            if(en>=0 && a[en+2]-a[en]==s[j].S*2) num++;
            res=max(res,num);
        }
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
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}