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
int n;

inline bool v(int i,int j){
    return i>=0&&j>=0&&i<n&&j<n;
}

void solve(){
    ii s,end;
    int d=1;
    cin>>n>>s.F>>s.S>>end.F>>end.S,s.F--,s.S--,end.F--,end.S--;
    queue<ii> q;
    if(s==end) {
        cout<<0<<endl;
        return;
    }
    q.push(s);
    q.push({-1,-1});
    vvi f(n,vi(n,0));
    while(!q.empty()){
        while(q.front().F!=-1){
            ii e=q.front();
            q.pop();
            int i=e.F+1,j=e.S+2;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
            i=e.F+1,j=e.S-2;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
            i=e.F-1,j=e.S+2;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
            i=e.F-1,j=e.S-2;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
            i=e.F+2,j=e.S+1;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
            i=e.F+2,j=e.S-1;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
            i=e.F-2,j=e.S+1;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
            i=e.F-2,j=e.S-1;
            if(v(i,j)&&!f[i][j]) f[i][j]=d,q.push({i,j});
        }
        q.pop();
        if(!q.empty()) q.push({-1,-1});
        ++d;
    }
    cout<<(!f[end.F][end.S]?-1:f[end.F][end.S])<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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