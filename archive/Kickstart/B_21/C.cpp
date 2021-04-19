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
int MAX=1e5,z,res=6;
vi pr;

void sieve(ll l,ll r){
    int m=sqrt(r)+1;
    vector<bool> temp(m+1,1),pr(r-l+1,1);
    for(int i=2;i*i<=m;i++){
        if(temp[i]){
            for(int j=i*i;j<=m;j+=i) temp[j]=0;
        }
    }
    //fr(i,2,m+1) if(temp[i]) cout<<i<<" ";
    for(int i=2;i<=m;i++){
        if(temp[i]){
            int x=(l/i)*i;
            if(x<l) x+=i;
            for(ll j=x;j<=r;j+=i) pr[j-l]=0;
        }
    }
    //fr(i,0,r-l+1) if(pr[i]) cout<<i+l<<" ";
    int prv=-1;
    fr(i,0,r-l+1){
        if(l+i<2) continue; 
        if(pr[i]){
            if(prv!=-1 && prv*(i+l)<=z) {
                res=prv*(i+l);
            }
            prv=i+l;
        }
    }
    cout<<res<<"\n";
}

void sieve1(){
    int prv=2;
    fr(i,3,MAX+1){
        if(pr[i]){
            if(prv*i<=z) res=prv*i;
            prv=i;
        }
    }
    cout<<res<<"\n";
}

void solve(){
    res=6;
    cin>>z;
    if(z<=1e9){
        sieve1();
    }
    else{
        int s=sqrt(z),l=max(0ll,(ll)s-MAX),r=min(s+MAX,z);
        sieve(l,r);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    pr = vector<int>(MAX+1,1);
    for(int i=2;i*i<=MAX;i++){
        if(pr[i]){
            for(int j=i*i;j<=MAX;j+=i) pr[j]=0;
        }
    }
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}