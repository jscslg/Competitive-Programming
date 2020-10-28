//~~~JsCode~~~
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
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
const int MAX=1001;
vi fact(MAX,1);

void solve(){
    int n,x,p,res=1,c1=0,c2=1;
    cin>>n>>x>>p;
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(mid==p) break;
        else if(p<mid) r=mid,res=(res*(n-x-c1))%MOD,c1++;
        else l=mid+1,res=(res*(x-c2))%MOD,c2++;
        //cout<<res<<" ";
    }
    cout<<(res*fact[n-c1-c2])%MOD<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    fr(i,1,MAX){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
/*
    n/2th num<x
*/