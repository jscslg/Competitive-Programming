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
int MAX=1e5+1;
int xt[]={0,-1,-2};

void solve(){
    int n,c=0;
    cin>>n;
    char a[n][n];
    vector<vii> x(3,vii());
    fr(i,0,n) fr(j,0,n) {
        cin>>a[i][j];
        if(a[i][j]=='X') {
            c++;
            x[(i+j)%3].pb({i,j});
        }
    }
    if(x[2].size()<=c/3){
        fr(i,0,x[2].size()) a[x[2][i].F][x[2][i].S]='O';
    }
    else if(x[1].size()<=c/3){
        fr(i,0,x[1].size()) a[x[1][i].F][x[1][i].S]='O';
    }
    else fr(i,0,x[0].size()) a[x[0][i].F][x[0][i].S]='O';
    fr(i,0,n){
        fr(j,0,n) cout<<a[i][j];
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
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}