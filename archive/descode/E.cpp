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
    int n,m,t1,t2,k;
    cin>>n>>m>>t1>>t2>>k;
    vi a(n),b(m),res(n,0);
    for(auto& i:a) cin>>i,i+=t1;
    for(auto& i:b) cin>>i;
    sort(all(a));
    sort(all(b));
    int j=0,m2=0;
    if(min(m,n)<=k) {
        cout<<-1<<endl;
        return;
    }
    f(i,0,n){
        if(j==m || i>k) break;
        while(b[j]<a[i]&&j<m) j++;
        int t=i+m-j;
        if(t<=k){
            cout<<-1<<endl;
            return;
        }
        if(j+k-i<m) m2=max(m2,b[j+k-i]);
    }
    cout<<m2+t2<<endl;
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