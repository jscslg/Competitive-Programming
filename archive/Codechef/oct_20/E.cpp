#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
//#define int ll
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
    vvi a(n);
    a[0].pb(1);
    f(i,1,n){
        int cur=0;
        f(j,0,(i*(i+1))/2+1){
            if(j<a[i-1].size()) cur+=a[i-1][j];
            if(j>i&&j-i-1<a[i-1].size()) cur-=a[i-1][j-i-1];
            cur=(cur+2)%2;
            a[i].pb(cur);
        }
    }
    f(i,0,30){
        f(j,0,i+1) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
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