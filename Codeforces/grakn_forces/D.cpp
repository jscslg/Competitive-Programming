#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define any_data int
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<any_data>
#define vvi vector<vi>
#define ii pair<any_data,any_data>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
void c_p_c(){ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout); }
const int mx=2e6;

void solve(){
    int n,m;
    cin>>n>>m;
    vii a(n),b(m);
    for(auto& i:a) cin>>i.F>>i.S;
    for(auto& i:a) cin>>i.F>>i.S;
    for(auto& i:a) cin>>i.F>>i.S;
    for(auto& i:b) cin>>i.F>>i.S;
    vi bad(mx,-1);
    for(auto& x:a){
        for(auto& y:b){
            if(x.F<=y.F && x.S<=y.S) {
                bad[y.F-x.F]=max(bad[y.F-x.F],y.S-x.S);
            }
        }
    }
    int cur=-1,res=mx;
    f_(i,mx-1,0){
        cur=max(cur,bad[i]);
        res=min(res,cur+i+1);
    }
    cout<<res<<endl;
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    c_p_c();
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}