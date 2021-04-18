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

int solve(vvi a,vvi b){
    int xx[8]={-2,-2,-1,-1,1,1,2,2},yy[8]={-1,1,-2,2,-2,2,-1,1};
    int m=a.size(),res=INT_MAX;
    vvi vis(8,vi(8,0));
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{b[0][0],b[0][1]}});
    while(!q.empty()){
        int s=q.front().first.first,d=q.front().first.second,i=q.front().second.first,j=q.front().second.second;
        q.pop();
        if(vis[i][j]) continue;
        fr(k,0,m){
            if(a[k][0]==i && a[k][1]==j)
        }
        vis[i][j]=1;
        fr(k,0,8){
            int x=i+xx[k],y=j+yy[k];
            if(x>=0 && y>=0 && x<8 && y<8){
                if(vis[x][y]) 
                q.push()
            }
        }
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
        int n;
        cin>>n;
        vvi a(n,vi(2)),b(1,vi(2));
        tr(i,a) tr(j,i) cin>>j;
        cin>>b[0][0]>>b[0][1];
        cout<<solve(a,b)<<" ";
        cout<<"\n";
    }
    return 0;
}