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
    int n,x,p,k;
    cin>>n>>x>>p>>k;
    vi a(n);
    for(auto& i:a) cin>>i;
    sort(all(a));
    int l=-1,r=-1,lb=1;
    f(i,0,n){
        if(a[i]==x) {
            if(l==-1) l=r=i+1;
            else r++;
        }
        if(a[i]<x) lb=i+2;
    }
    //cout<<l<<" "<<" "<<r<<" "<<lb<<"x";
    if(l!=-1){
        if(p>=l&&p<=r) cout<<0;
        else if(k>=l&&k<=r) cout<<-1;
        else if(p>r && k>r){
            if(k>=p) cout<<p-r;
            else cout<<-1;
        }
        else if(p<l && k<l){
            if(k<=p) cout<<l-p;
            else cout<<-1;
        }
        else cout<<-1;
        cout<<endl;
        return;
    }
    if(k<lb && p<lb){
        if(p>=k) cout<<lb-p;
        else cout<<-1;
    }
    else if(k>=lb && p>=lb){
        if(p<=k) cout<<p-lb+1;
        else cout<<-1;
    }
    else cout<<-1;
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