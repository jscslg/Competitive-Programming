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

int area(int x1,int x2,int x3,int y1,int y2,int y3){
    return x1 *(y2 - y3 ) + x2 *(y3 - y1 )+x3*(y1 - y2);
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int maxx = max({a,b,c});

    int sum = (a + b + c);

    if (2 * maxx > sum || sum % 2 == 1) {
        cout << "NO\n";
        return;
    }
    int x1 = 0, y1 = 0;
    int x2 = max({a,b,c}), y2 = 0;
 
    int x3 = (max({a,b,c}) + (a+b+c-max({a,b,c})-min({a,b,c})- min({a,b,c}))) / 2,y3 = (a+b+c - 2*max({a,b,c})) / 2;

    int xx=area(x1,x2,x3,y1,y2,y3);
    int yy=area(x1,x3,x2,y1,y3,y2);

    cout<<"YES\n";

    int t=1-min({x1,x2,x3});
    x1+=t,x2+=t,x3+=t;
    t=1-min({y1,y2,y3});
    y1+=t,y2+=t,y3+=t;
    
        cout<<x1<<" "<<y1<<"\n";
        cout<<x2<<" "<<y2<<"\n";
        cout<<x3<<" "<<y3<<"\n";
   
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