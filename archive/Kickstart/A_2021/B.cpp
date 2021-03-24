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
//#define int ll
#define tr(i,a) for(auto& i:a)
#define fr(i,n) for(int i=0;i<(n);++i)
#define fr1(i,n) for(int i=1;i<=(n);++i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5;

int calc(int a,int b){
    a++,b++;
    return max(0,min(a/2,b)+min(b/2,a)-2);
}

void solve(){
    int r,c,res=0;
    cin>>r>>c;
    vvi a(r,vi(c));
    tr(i,a) tr(j,i) cin>>j;
    vvi up(r,vi(c,0)),down(r,vi(c,0)),right(r,vi(c,0)),left(r,vi(c,0));
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] && a[i-1][j]) up[i][j]=up[i-1][j]+1;
        }
    }
    for(int i=r-2;i>=0;i--){
        for(int j=0;j<c;j++){
            if(a[i][j] && a[i+1][j]) down[i][j]=down[i+1][j]+1;
        }
    }
    for(int i=1;i<c;i++){
        for(int j=0;j<r;j++){
            if(a[j][i] && a[j][i-1]) left[j][i]=left[j][i-1]+1;
        }
    }
    for(int i=c-2;i>=0;i--){
        for(int j=0;j<r;j++){
            if(a[j][i] && a[j][i+1]) right[j][i]=right[j][i+1]+1;
        }
    }
    fr(i,r){
        fr(j,c){
            if(a[i][j]){
                res+=calc(up[i][j],right[i][j]);
                res+=calc(up[i][j],left[i][j]);
                res+=calc(down[i][j],right[i][j]);
                res+=calc(down[i][j],left[i][j]);
            }
        }
    }
    cout<<res;
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
        cout<<"\n";
    }
    return 0;
}