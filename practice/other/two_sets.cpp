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
    if(n%4==3) {
        cout<<"YES\n";
        int k=n/4;
        cout<<k*2+2<<"\n1 2 ";
        for(int i=5;i<n;i+=4){
            cout<<i<<" "<<i+1<<" ";
        }
        cout<<"\n"<<k*2+1<<"\n3 ";
        for(int i=4;i<n;i+=4){
            cout<<i<<" "<<i+3<<" ";
        }
    }
    else if(n%4==0){
        cout<<"YES\n";
        int k=n/4;
        cout<<k*2<<"\n";
        for(int i=2;i<n;i+=4){
            cout<<i<<" "<<i+1<<" ";
        }
        cout<<"\n"<<k*2<<"\n";
        for(int i=1;i<n;i+=4){
            cout<<i<<" "<<i+3<<" ";
        }
    }
    else cout<<"NO";
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