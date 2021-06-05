/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:(a))
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
//#define int ll
int MAX=1e5;

void solve(){
    int n,m;
    string s;
    cin>>n>>m>>s;
    vi f(n,INT_MAX);
    int c=0,i=0;
    while(i<n&&s[i]!='1') i++;
    while(i<n){
        if(s[i]=='1') c=0;
        else c++;
        f[i++]=c;
    }
    c=0,i=n-1;
    while(i>=0 && s[i]!='1') i--;
    while(i>=0){
        if(s[i]=='1') c=0;
        else c++;
        if(f[i]==c && s[i]!='1') f[i]=INT_MAX;
        else f[i]=min(f[i],c);
        i--;
    }
    fr(i,0,n){
        if(f[i]<=m) cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";
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