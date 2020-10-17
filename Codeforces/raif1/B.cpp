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
const int MAX=1e6;
void initialize(){}

void solve(){
    int n;
    string s;
    cin>>n>>s;
    int n1=0,n2=0;
    vi a;
    bool start=0;
    for(int i=0;i<n;){
        if(s[i]=='>') n1++,i++;
        else if(s[i]=='<') n2++,i++;
        else{ 
            int cnt=0;
            if(i==0) start=1;
            while(i<n && s[i]=='-') ++i,++cnt;
            if(i==n&&a.size()>0&&start) a[0]+=cnt; 
            else a.pb(cnt);
        }
    }
    if(n1==0||n2==0) cout<<n;
    else{
        int res=0;
        f(i,0,a.size()) res+=a[i]+1;
        cout<<res;
    }
    cout<<endl;
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