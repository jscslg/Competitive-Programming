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
    int x,y;
    cin>>x>>y;
    int n=sqrt(x+y);
    if(n*n!=x+y || (x-n)&1 || y&1){
        cout<<"NO\n";
        return;
    }
    x-=n,x/=2,y/=2;
    fr(i,0,n-1){
        int a=n-1-i,b=i,z=a*(b+1);
        if(z==y){
            cout<<"YES\n"<<n<<"\n";
            int c=2;
            fr(j,0,a){
                cout<<"1 "<<c<<"\n";c++;
            }
            fr(j,0,b){
                cout<<"2 "<<c<<"\n";c++;
            }
            return;
        }
    }
    cout<<"NO\n";
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