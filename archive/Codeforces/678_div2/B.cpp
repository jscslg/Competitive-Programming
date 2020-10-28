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
//#define int ll
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
const int MAX=1e5+1;
vector<bool> pr(MAX,1);

void solve(){
    int n,m;
    cin>>n;
    fr(i,n-1,1e5-1){
        if(pr[i]&&!pr[i-n+1]) {
            m=i-n+1;break;
        }
    }
    fr(i,0,n){
        fr(j,0,n){
            if(i==j) cout<<m<<" ";
            else cout<<1<<" ";
        }
        cout<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    for(int i=2;i*i<=MAX;i++){
        if(pr[i]){
            for(int j=i*i;j<=MAX;j+=i) pr[j]=0;
        }
    }
    pr[0]=0,pr[1]=0;
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
/*
4 0 1
1 4 0
0 1 4
1 1 1
1 0 0 
*/