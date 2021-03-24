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
int n,res;
vvi a,b;

bool check(vvi z,int d){
    if(d==0) return 1;
    vi r(n),c(n);
    fr(i,n){
        int x=0,y=0;
        fr(j,n) {
            if(z[i][j]) x++;
            if(z[j][i]) y++;
        }
        r[i]=x,c[i]=y;
    }
    int e=d,f=d;
    while(f--){
        fr(i,n){
            fr(j,n){
                if(!z[i][j]) continue;
                if(r[i]==1 || c[j]==1) z[i][j]=0,r[i]--,c[j]--,e--;
                if(!e) return 1;
            }
        }
    }
    return 0;
}

void rec(int d){
    for(int k=0;k<(1<<d);k++){
        vvi c(n,vi(n,0));
        int e=1,f=0,sum=0;
        fr(i,n) {
            fr(j,n){
                if(a[i][j]==-1){
                    if(e&k) {
                        c[i][j]=1,f++;
                    }
                    else sum+=b[i][j];
                    e<<=1;
                }
            }
        }
        if(check(c,f)) res=min(res,sum);
    }
}

void solve(){
    cin>>n;
    a.assign(n,vi(n,0));
    b.assign(n,vi(n,0));
    res=0;
    vi r(n),c(n);
    tr(i,a) tr(j,i) cin>>j;
    tr(i,b) tr(j,i) cin>>j,res+=j;
    tr(i,r) cin>>i;
    tr(i,c) cin>>i;
    int d=0;
    tr(i,a) tr(j,i) if(j==-1) d++;
    rec(d);
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