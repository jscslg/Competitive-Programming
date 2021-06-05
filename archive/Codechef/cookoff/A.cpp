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

void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int val=1,res=0;
    if(c<a || d<b){
        cout<<"0\n";
        return;
    }
    swap(a,b);
    swap(c,d);
    fr(i,1,b){
        val+=i+1;
    }
    fr(i,1,a){
        val+=b+i-1;
    }
    //cout<<val<<" ";
    res+=val;
    fr(i,b,d){
        val+=a+i;
        //cout<<val<<" ";
        res+=val;
    }
    fr(i,a,c){
        val+=d+i-1;
        //cout<<val<<" ";
        res+=val;
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
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}