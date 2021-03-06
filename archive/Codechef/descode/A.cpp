#include <bits/stdc++.h>
#define ll long long
#define ldb long double
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
const int mx=1e6;

void solve(){
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    for(auto& i:a) cin>>i;
    ll m=n+1,cur=0,i=0,j=0;
    while(j<n){
        while(cur<=s&&j<n){
            cur+=a[j++];
        }
        while(cur>s&&i<n){
            m=min(m,j-i);
            cur-=a[i++];
        }
    }
    if(m==n+1) cout<<-1<<endl;
    else cout<<m<<endl;
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    c_p_c();
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}