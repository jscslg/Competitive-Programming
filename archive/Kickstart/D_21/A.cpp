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
#define int ll
const int MOD = 1000000007, MOD2 = 998244353;
const int MAX=1e5;

int ret(int a,int b){
    return abs(a-b)%2==0;
}
int ret2(int a,int b,int c){
    return b-a == c-b;
}
int calc(ve<vi> a){
    int res=0;
    res += ret2(a[0][0],a[1][1],a[2][2]);
    res += ret2(a[0][2],a[1][1],a[2][0]);
    res += ret2(a[1][0],a[1][1],a[1][2]);
    res += ret2(a[0][1],a[1][1],a[2][1]);
    return res;
}

void solve(){
    int res=0;
    ve<vi> a(3,vi(3));
    fr(i,0,3){
        fr(j,0,3){
            if(i==1&&j==1) a[i][j]=0;
            else cin>>a[i][j];
        }
    }
    if(ret(a[0][0],a[2][2])){
        a[1][1]=(a[0][0]+a[2][2])/2;
        res = max(res,calc(a));
    }
    if(ret(a[0][2],a[2][0])){
        a[1][1]=(a[0][2]+a[2][0])/2;
        res = max(res,calc(a));
    }
    if(ret(a[1][0],a[1][2])){
        a[1][1]=(a[1][0]+a[1][2])/2;
        res = max(res,calc(a));
    }
    if(ret(a[0][1],a[2][1])){
        a[1][1]=(a[0][1]+a[2][1])/2;
        res = max(res,calc(a));
    }
    res += ret2(a[0][0],a[0][1],a[0][2]);
    res += ret2(a[0][0],a[1][0],a[2][0]);
    res += ret2(a[2][0],a[2][1],a[2][2]);
    res += ret2(a[0][2],a[1][2],a[2][2]);
    cout<<res<<"\n";
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
        cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifdef LOCAL_JUDGE
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cerr << "Time taken : " << duration.count() / 1000000.0 << "seconds"<< "\n";
    #endif
    return 0;
}