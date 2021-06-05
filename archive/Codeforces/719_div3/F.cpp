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
//#define int ll
int MAX=1e5;

int ask(int l,int r){
    int x;
    cout<<"? "<<l+1<<" "<<r+1<<endl;
    cin>>x;
    return x;
}

void solve(){
    int n,t,k;
    cin>>n>>t>>k;
    int l=0,r=n-1;
    while(l<r){
        int m=l+(r-l)/2;
        int x = m-l+1-ask(l,m);
        if(x>=k) r=m;
        else k-=x,l=m+1;
    }
    cout<<"! "<<l+1<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifdef LOCAL_JUDGE
    // freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    // #endif
    //INIT
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}