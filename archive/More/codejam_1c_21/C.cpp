/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
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
int MAX=1e5,res;

int inv(int n){
    if(n==0) return 1;
    int p=log2(n)+1;
    return n^((1ll<<p)-1);
}

void rec(int a,int b,int i){
    if(a==b) res=min(res,i-1);
    if(i==20) return;
    rec(inv(a),b,i+1);
    rec(a*2,b,i+1);
}

void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.size(),n2=s2.size(),a=0,b=0;
    fr(i,0,n1) if(s1[i]=='1') a+=(1<<(n1-i-1));
    fr(i,0,n2) if(s2[i]=='1') b+=(1<<(n2-i-1));
    //cout<<a<<" "<<b<<"\n";
    res=INT_MAX;
    rec(a,b,1);
    if(res==INT_MAX) cout<<"IMPOSSIBLE\n";
    else cout<<res<<"\n";
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