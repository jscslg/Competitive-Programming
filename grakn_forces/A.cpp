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

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n),c(n);
    for(auto& i:a) cin>>i;
    for(auto& i:b) cin>>i;
    for(auto& i:c) cin>>i;
    cout<<a[0]<<" ";
    int x=a[0];
    f(i,1,n){
        if(i==n-1){
            if(a[i]!=x&&a[i]!=a[0]) {
            x=a[i];
            cout<<x<<" ";
        }
        else if(b[i]!=x&&b[i]!=a[0]) {
            x=b[i];
            cout<<x<<" ";
        }
        else if(c[i]!=x&&c[i]!=a[0]) {
            x=c[i];
            cout<<x<<" ";
        }
        }
        else {
        if(a[i]!=x) {
            x=a[i];
            cout<<x<<" ";
        }
        else if(b[i]!=x) {
            x=b[i];
            cout<<x<<" ";
        }
        else if(c[i]!=x) {
            x=c[i];
            cout<<x<<" ";
        }
        }
    }
    cout<<endl;
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