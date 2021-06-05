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

void solve(){
    int n,m,res=0;
    cin>>n>>m;
    vi a(n),f(n+2,0);
    fr(i,0,n){
        int x;cin>>x;
        a[i]=x;
        res+=!f[x-1];
        f[x]=i+1;
    }
    fr(i,0,m){
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        if(x==y) {
            cout<<res<<"\n";
            continue;
        }
        int b=a[x-1],c=a[y-1];
        if(b==c+1) {
            res--;
            if(f[b+1]<=y&&f[b+1]>x) res++;
            if(f[c-1]>=x&&f[c-1]<y) res++;
        }
        else if(c==b+1) {
            res++;
            if(f[b-1]<=y&&f[b-1]>x) res--;
            if(f[c+1]>=x&&f[c+1]<y) res--;
        }
        else {
            if(f[b-1]<=y&&f[b-1]>x) res--;
            if(f[b+1]<=y&&f[b+1]>x) res++;
            if(f[c-1]>=x&&f[c-1]<y) res++;
            if(f[c+1]>=x&&f[c+1]<y) res--;
        }
        f[b]=y,f[c]=x,swap(a[x-1],a[y-1]);
        cout<<res<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
  //  cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}