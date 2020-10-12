#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
//#define int ll
#define MOD 1000000007
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define INIT 0
const int mx=1e6;
void initialize(){}

void solve(){
    int n;
    cin>>n;
    int t=n;
    if(t%3==0) {
            cout<<t/3<<" "<<0<<" "<<0<<endl;
            return;
        }
    while(t>=0){
        if(t%5==0) {
            cout<<(n-t)/3<<" "<<t/5<<" "<<0<<endl;
            return;
        }
        if(t%7==0) {
            cout<<(n-t)/3<<" "<<0<<" "<<t/7<<endl;
            return;
        }
        t-=3;
    }
    t=n;
    while(t>=0){
        if(t%7==0) {
            cout<<0<<" "<<(n-t)/5<<" "<<t/7<<endl;
            return;
        }
        t-=5;
    }
    cout<<-1<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}