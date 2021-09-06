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
int xx[]={1,0,-1,0},yy[]={0,1,0,-1};

void solve(){
    int n,m;
    cin>>n>>m;
    ve<string> g(n);
    ve<vi> vis(n,vi(m,0));
    queue<ar(2)> q;
    fr(i,0,n) {
        cin>>g[i];
        fr(j,0,m){
            if(g[i][j]!='.'&&q.empty()) q.push({i,j}),vis[i][j]=1;
        }
    }

    if(q.empty()) {
        g[0][0]='R',vis[0][0]=1;
        q.push({0,0});
    }
    while(!q.empty()){
        ar(2) e=q.front();
        q.pop();
        fr(i,0,4){
            int X=xx[i]+e[0],Y=yy[i]+e[1];
            if(X>=0&&X<n&&Y>=0&&Y<m&&!vis[X][Y]){
                vis[X][Y]=1;
                q.push({X,Y});
                char ch=g[e[0]][e[1]];
                if(g[X][Y]==ch){
                    cout<<"NO\n";
                    return;
                }
                if(ch=='R') g[X][Y]='W';
                else g[X][Y]='R';
            }
        }
    }

    cout<<"YES\n";
    tr(e,g){
        cout<<e<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
        auto start = chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifdef LOCAL_JUDGE
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cerr << "Time taken : " << duration.count() / 1000000.0 << "seconds"<< "\n";
    #endif
    return 0;
}