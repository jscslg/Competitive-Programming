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
//#define int ll
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

void solve(){
    int c0,c1,n,h;
    string s;
    cin>>n>>c0>>c1>>h>>s;
    int n0=0,n1=0;
    tr(e,s) {
        if(e=='1') n1++;
        else n0++;
    }
    int res=INT_MAX;
    fr(i,0,n0+1){
        res=min(res,h*i+c1*(n1+i)+c0*(n0-i));
    }
    fr(i,0,n1+1){
        res=min(res,h*i+c1*(n1-i)+c0*(n0+i));
    }
    cout<<res<<endl;
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