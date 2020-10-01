#include <bits/stdc++.h>
#define ll long long
#define ld long double
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
    int n,s;
    cin>>n>>s;
    vi a(n);
    for(auto& i:a) cin>>i;
    ld i=0,j=n-1,sa=1,sb=1,d1=0,d2=s;
    ld res=0,l,r;
    while(i<=j){
        l=((a[i]-d1)*1.0)/sa,r=((d2-a[j])*1.0)/sb;
        //cout<<l<<" "<<r<<"x";
        if(l<=r) res+=l,d1=a[i],++i,++sa,d2=(d2-l*sb);
        else res+=r,d2=a[j],--j,++sb,d1=(d1+r*sa);
    }
    res+=(d2-d1)/(sa+sb);
    cout<<fixed<<setprecision(10)<<res<<endl;
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