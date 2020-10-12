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
    string s;
    cin>>s;
    vi b;
    for(int i=0;i<n;){
        char c=s[i];
        int cnt=0;
        while(i<n && s[i]==c) ++i,++cnt;
        b.pb(cnt);
    }
    int n1=b.size(),res=0;
    vi c(n1),d;
    c[n1-1]=0;
    f_(i,n1-2,0){
        c[i]=c[i+1]+b[i+1]-1;
    }
    //f(i,0,n1) cout<<c[i]<<" ";
    f(i,0,n1) if(b[i]>1) d.pb(i);
    int j=0,n2=d.size();
    for(int i=0;i<n1;){
        if(b[i]==1){
            //while(j<n2 && (d[j]<=i || b[d[j]]==1)) ++j;
            if(j<n2 && b[d[j]]==1) ++j;
            if(j<n2) b[d[j]]--,++i;
            else i+=2;
            ++res;
        }
        else {
            if(d[j]==i) ++j;
            ++i,++res;
        }
    }
    cout<<res<<endl;
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