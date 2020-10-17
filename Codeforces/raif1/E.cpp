#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define int ll
#define MOD 1000000007
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
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

int c(int n,int p){
    int x=n/p,y=n%p,z=p-y;
    return y*(x+1)*(x+1)+z*x*x;
}

void solve(){
    int n,k,sum=0,res=0;
    cin>>n>>k;
    priority_queue<iii> h;
    f(i,0,n) {
        int a;
        cin>>a;
        h.push({c(a,1)-c(a,2),{a,2}});
        res+=a*a;
    }
    k-=n;
    f(i,0,k){
        iii e=h.top();
        h.pop();
        res-=e.F;
        int a=e.S.F,b=e.S.S;
        h.push({c(a,b)-c(a,b+1),{a,b+1}});
    }
    cout<<res;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}