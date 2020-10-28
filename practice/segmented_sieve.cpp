#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
//#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
const int MAX=1e5+1;

void solve(){
    int l,r;
    cin>>l>>r;
    int m=sqrt(r);
    vector<bool> temp(m+1,1),pr(r-l+1,1);
    for(int i=2;i*i<=m;i++){
        if(temp[i]){
            for(int j=i*i;j<=m;j+=i) temp[j]=0;
        }
    }
    for(int i=2;i<=m;i++){
        if(temp[i]){
            int x=max(i*i,((l-1)/i+1)*i);
            for(ll j=x;j<=r;j+=i) pr[j-l]=0;
        }
    }
    fr(i,0,r-l+1) if(pr[i]&&l+i>1) cout<<l+i<<endl;
    cout<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    fr(i,1,t+1){
    //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}