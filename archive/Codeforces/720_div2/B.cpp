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
int MAX=1e5;

void solve(){
    int n;
    cin>>n;
    vi a(n);
    int x=a[0],y=0,m=INT_MAX,mi;
    fr(i,0,n) {
        cin>>a[i];
        if(a[i]<m) m=a[i],mi=i;
    }
    cout<<n-(mi==0?1:0)<<"\n";
    if(mi!=0) {
        cout<<"1 "<<mi+1<<" "<<m<<" "<<a[0]<<"\n";
        swap(a[0],a[mi]);
    }
    fr(i,1,n){
        cout<<i+1<<" 1 "<<a[0]+i<<" "<<a[0]<<"\n";
    }
    // int l=-1;
    // fr(i,0,n-1){
    //     if(__gcd(a[i],a[i+1])!=1) {
    //         if(l!=-1) b.pb({l,i+1}),i++;
    //         else l=i+1,i++;
    //     }
    // }
    // if(l!=-1) b.pb({0,l});
    // cout<<b.size()<<"\n";
    // tr(e,b) cout<<e.F+1<<" "<<e.S+1<<" 1 1\n";
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