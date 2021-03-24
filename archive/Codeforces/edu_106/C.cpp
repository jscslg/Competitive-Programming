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
#define int ll
#define tr(i,a) for(auto& i:a)
#define fr(i,n) for(int i=0;i<(n);++i)
#define fr1(i,n) for(int i=1;i<=(n);++i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5;

void solve(){
    int n,sum=0,res=LLONG_MAX;
    cin>>n;
    vi a(n);
    tr(i,a) cin>>i;
    int ma=a[0],mb=a[1],ra=n,rb=n;
    sum+=a[0],ra--;
    for(int i=1;i<n;i++){
        if(i%2==0){
            ma=min(ma,a[i]);
            sum+=a[i],ra--;
        }
        else {
            mb=min(mb,a[i]);
            sum+=a[i],rb--;
        }
        res=min(sum+ma*ra+mb*rb,res);
    }
    cout<<res<<"\n";
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