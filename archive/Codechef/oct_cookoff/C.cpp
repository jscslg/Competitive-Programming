#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
//#define int ll
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
    int n,k,x;
    cin>>n>>k>>x;
    if(k<=n-1) cout<<"YES\n";
    //else if(k>(n*(n-1))/2) cout<<"NO\n";
    else{
        int b=0,c=log2(x)+1,d=1,e=0;
        fr(i,c) if((1<<i)&x) ++b; 
        int p=pow(k,1.0/b);
        //cout<<b<<"x"<<p<<" ";
        fr(i,b) d*=p;
        while(d<=x) d=(d*(p+1))/p,++e;
        b-=e;
        int res=b*p+e*(p+1);
        //cout<<res;
        if(n>=res) cout<<"YES\n";
        else cout<<"NO\n";
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
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}