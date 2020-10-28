#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define int ll
#define MOD 1000000007
#define fr(i,a) for(int i=0;i<(a);++i)
#define tr(i,a) for(auto& i:a)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define INIT 0
const int MAX=1e6;
void initialize(){}

void solve(){
    int x,y,res;
    vi c(6);
    cin>>y>>x;
    fr(i,6) cin>>c[i];
    if(y==0){
        if(x==0) res=0;
        else if(x>0) res=min(x*c[1],x*c[0]+x*c[2]);
        else if(x<0) res=min(x*);
    }
    else if(y>0){
        if(x==0) res=min(y*c[5],y*c[1]+y*c[3]);
        else if(x>0) res=min(x*c[1]+y*c[5],min(x,y)*c[0]+abs(x-y)*c[5]);
        else x*=-1,res=min(x*c[4]+y*c[5],min(x,y)*)
    }
    else if(y<0){
        if(y==0) x*=-1,res=min(y*c[5],y*c[1]+y*c[3]);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}