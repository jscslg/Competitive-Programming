/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using hmax=priority_queue<T>;
template<class T> using hmin=priority_queue<T,vector<T>,greater<T>>;
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:(a))
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define ar(n) array<int,n>
#define ve vector
#define vi ve<int>
//#define int ll
const int MOD = 1000000007, MOD2 = 998244353;
const int MAX=1e5;
int k;
ve<vi> a,b;

int rec(int i,int j){
    if(i==-1) return 1;
    int x=rec(i-1,j*2),y=rec(i-1,j*2+1);
    if(a[i][j]==1) b[i][j]=y;
    else if(a[i][j]==0) b[i][j]=x;
    else b[i][j]=x+y;
    return b[i][j];
}

void solve(){
    int q,l=0;
    cin>>k;
    string s;
    cin>>s>>q;
    a = ve<vi>(k);
    b = ve<vi>(k);
    fr(i,0,k){
        fr(j,0,pow(2,k-i-1)) a[i].pb(s[l++]-'0'),b[i].pb(0);
    }
    rec(k-1,0);
    while(q--){
        int x,y=0;
        char c;
        cin>>x>>c,x--;
        int p=pow(2,k-1),j=0;
        while(x>=p){
            x-=p,p=p/2,j++;
        }
        a[j][x]=c-'0';
        fr(i,j,k){
            if(a[i][x]==15) b[i][x]=(i==0?1:b[i-1][x*2])+(i==0?1:b[i-1][x*2+1]);
            else if(a[i][x]==1) b[i][x]=(i==0?1:b[i-1][x*2+1]);
            else b[i][x]=(i==0?1:b[i-1][x*2]);
            x/=2;
        }
        cout<<b[k-1][0]<<"\n";
        // fr(i,0,k){
        //     tr(e,b[i]) cout<<e<<" ";
        //     cout<<"\n";
        // }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}