/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1;
int get(int n, int k)  {  
    int ans = 0;  
    for (int j = 1;  
        j * j <= n; j++) {  
        if (n % j == 0) {  
            if (j <= k) {  
                ans = max(ans, j);  
            }  
            if (n / j <= k) {  
                ans = max(ans, n / j);  
            }  
        }  
    }  
    return ans;  
}  
void solve(){
    int n,m,gcd=0;
    cin>>n>>m;
    vi a(m);
    tr(e,a) cin>>e,gcd=__gcd(gcd,e);
    int s=sqrt(gcd),t=gcd;
    int b=get(t,n);
    //cout<<b<<" ";
    // fr(i,2,s+1){
    //     while(t%i==0){
    //         if(t<=n) break;
    //         t=t/i;
    //     }
    //     if(t<=n) break;
    // }
    //if(t>n) t=1;
    cout<<n-b<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}