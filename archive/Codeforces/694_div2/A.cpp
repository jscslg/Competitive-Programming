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
#define TR(i,a) for(auto& i:a)
#define F0(i,n) for(int i=0;i<(n);++i)
#define F1(i,n) for(int i=1;i<=(n);++i)
#define FO(i,a,b) for(int i=(a);i<(b);++i)
#define FR(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+4e3+1;

void solve(){
    int n,x,s=0,c=0;
	cin >> n >> x;
	vi a(n);
	TR(i,a) cin >> i;
	F0(i,n) s+=a[i];
	F0(i,n) c+=(a[i]+x-1)/x;
	cout << (s+x-1)/x << " " << c << endl;
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