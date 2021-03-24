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

void solve(){
    int n;
    cin>>n;
    vi a(n);
    tr(e,a) cin>>e;
    int e=a[0];
    fr(i,1,n){
        if(a[i]>e){
            int x=a[i]/e,y=ceil((a[i]*1.0)/e);
            int c=e*x,d=e*y;
            if(abs(a[i]-c)<=abs(a[i]-d)) a[i]=c;
            else {
                if(d>1e9) a[i]=c;
                else a[i]=d;
            }
        }
        else if(a[i]<e){
            int c=1,d=e;
            if(abs(a[i]-c)<=abs(a[i]-d)) a[i]=c;
            else a[i]=d;
        }
        e=a[i];
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