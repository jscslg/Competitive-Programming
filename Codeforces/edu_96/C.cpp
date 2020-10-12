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
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define INIT 0
const int mx=1e6;
void initialize(){}

void solve(){
    int n;
    cin>>n;
    if(n==2) {
        cout<<2<<endl<<1<<" "<<2<<endl;
        return;
    }
    cout<<2<<endl;
    cout<<n<<" "<<n-2<<endl;
    cout<<n-1<<" "<<n-1<<endl;
    for(int i=n-1,j=n-3;j>=1;j--,i--){
        cout<<i<<" "<<j<<endl;
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