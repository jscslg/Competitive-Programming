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
int MAX=1e4;
vi pr;

void solve(){
    int n,x,s=0;
    cin>>n>>x;
    vi a(n);
    bool f=0;
    tr(e,a) {
        cin>>e,s+=e;
        if(e!=x) f=1;
    }
    if(s==x || f==0) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    sort(all(a));
    s=0;
    fr(i,0,n){
        s+=a[i];
        if(s==x) {
            swap(a[i],a[i+1]);
            break;
        }
    }
    tr(e,a) cout<<e<<" ";
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