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
    int n;
    cin>>n;
    vvi a(n,vi(n,-1));
    fr(i,0,n) cin>>a[i][i];
    fr(i,0,n){
        int t=a[i][i];
        int j=i,k=i;
        fr(x,0,t-1){
            if(k>0 && a[j][k-1]==-1) k--,a[j][k]=t;
            else if(j<n-1 && a[j+1][k]==-1) j++,a[j][k]=t;
            else{
                //cout<<j<<"x"<<k;
                // fr(i,0,n){
                //     fr(j,0,i+1) cout<<a[i][j]<<" ";
                //     cout<<"\n";
                // }
                cout<<"-1\n";
                return;
            }
        }
    }
    fr(i,0,n){
        fr(j,0,i+1) cout<<a[i][j]<<" ";
        cout<<"\n";
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