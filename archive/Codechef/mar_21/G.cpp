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
    int n,m,e,cnt=0;
    cin>>n>>m>>e;
    if(n==0 || m==0){
        cout<<"0\n";
        return;
    }
    vector<string> a(n),b(n);
    tr(i,a) cin>>i;
    tr(i,b) cin>>i;
    tr(i,a) tr(j,i) if(j-'0') cnt++;
    if(cnt&1){
        cout<<"-1\n";
        return;
    }
    vector<tuple<char,int,int,int>> res;
    fr(i,0,n){
        int j=(a[i][0]-'0'+1)%2;
        for(int k=j+2;k<m;k+=4){
            a[i][k]='0',a[i][k-2]='0';
            res.pb({'R',(i+1),(k+1),(k-1)});
        }
    }
    for(int i=m-1;i>=0&&i>=m-2;i--){
        int x=-1;
        fr(j,0,n){
            if(a[j][i]-'0'){
                if(x==-1) x=j;
                else res.pb({'C',i+1,x+1,j+1}),a[j][i]='0',a[x][i]='0',x=-1;
            }
        }
    }
    ii x={-1,-1},y;
    fr(i,0,n) {
        fr(j,0,m) {
            if(a[i][j]-'0'){
                if(x.F==-1) x={i+1,j+1};
                else y={i+1,j+1};
            }
        }
    }
    if(x.F!=-1){
        res.pb({'R',x.F,x.S,y.S});
        res.pb({'C',y.S,x.F,y.F});
    }
    cout<<res.size()<<"\n";
    if(!e) return;
    tr(i,res) {
        cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<" "<<get<3>(i)<<"\n";
    }
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