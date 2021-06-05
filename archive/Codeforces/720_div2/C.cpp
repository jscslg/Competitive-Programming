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

int ask(int t,int i,int j,int x){
    cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
    int x;
    cin>>x;
    return x;
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n-2;i+=3){
        int mn=ask(2,i,i+1,1),mx=ask(1,i,i+1,n-1);
        int mn2=ask(2,i+1,i+2,1),mx2=ask(1,i+1,i+2,n-1);
        if(mn2!=2&&mx2!=n-1&&mn!=2&&mx!=n-1){
            if(mn2==mn) a[i+1]=mn;
            else if(mx2==mx) a[i+1]=mx;
            else if(mn==mx2) a[i+1]=mn;
            else if(mx==mn2) a[i+1]=mx;
            if(mn==a[i+1]) a[i]=mx;
            else a[i]=mn;
            if(mn2==a[i+1]) a[i+2]=mx2;
            else a[i+2]=mn2;
        }
        else{
            if(mn==2){
                int x=
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
        solve();
    }
    return 0;
}