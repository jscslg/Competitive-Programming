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
#define int ll
int MAX=1e5;

ll powm(ll number,ll exponent=MOD-2){
    ll ret=1;
    while(exponent>0){
        if(exponent&1) ret=(ret*number)%MOD;
        exponent>>=1,number=(number*number)%MOD;
    }
    return ret;
}

void solve(){
    int n,k,res=0;
    string s;
    cin>>n>>k>>s;
    int m=(n+1)/2;
    fr(i,0,m){
        int d=s[i]-'a';
        res=(res+(powm(k,m-i-1)*d)%MOD)%MOD;
    }
    for(int i=(n-1)/2,j=n/2;i>=0;i--,j++){
        if(s[j]==s[i]) continue;
        if(s[j]<s[i]) break;
        else{
            res=(res+1)%MOD;
            break;
        }
    }
    cout<<res<<"\n";
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
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}