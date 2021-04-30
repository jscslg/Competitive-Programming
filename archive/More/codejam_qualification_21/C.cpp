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
int n,c;
vi a,vis;

bool check(vi a){
    int res=0;
    fr(i,0,n-1){
        int mi=i;
        fr(j,i+1,n){
            if(a[j]<a[mi]) mi=j;
        }
        res+=mi-i+1;
        for(int j=i,k=mi;j<(mi+i+1)/2;j++,k--){
            swap(a[j],a[k]);    
        }
    }
    return res==c;
}

bool rec(int i){
    if(i==n){
        if(check(a)) {
            tr(e,a) cout<<e+1<<" ";
            cout<<"\n";
            return 1;
        }
    }
    fr(j,0,n){
        if(!vis[j]){   
            a[i]=j;
            vis[j]=1;       
            if(rec(i+1)) return 1;
            vis[j]=0;
        }
    }
    return 0;
}

void solve(){
    cin>>n>>c;
    a.assign(n,0);
    vis.assign(n,0);
    if(rec(0)) return;
    cout<<"IMPOSSIBLE\n";
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