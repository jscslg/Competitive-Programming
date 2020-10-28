#include <bits/stdc++.h>
#define ll long long
#define ldb long double
#define MOD 1000000007
#define any_data ll
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
#define INIT 0
using namespace std;
void c_p_c(){ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout); }
const int mx=1e6;
void initialize(){}

void solve(){
    ll n,m,res=0;
    cin>>n>>m;
    vvi a(n,vi(m));
    f(i,0,n) f(j,0,m) cin>>a[i][j];
    for(int i=0,j=n-1;i<j;i++,j--){
        for(int k=0,l=m-1;k<l;k++,l--){
            vi x(4);
            x[0]=a[i][k],x[1]=a[j][k],x[2]=a[i][l],x[3]=a[j][l];
            sort(all(x));
            f(m,0,4) res+=abs(x[1]-x[m]);
        }
        //cout<<res<<" ";
    }
    if(n%2==1){
        f(i,0,m/2){
            res+=abs(a[n/2][m-i-1]-a[n/2][i]);
        }
    }
    if(m%2==1){
        f(i,0,n/2){
            res+=abs(a[n-i-1][m/2]-a[i][m/2]);
        }
    }
    cout<<res<<endl;
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    c_p_c();
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