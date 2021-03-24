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
int MAX=1e7+1;
vi pr(MAX,1);


void solve(){
    int n,k,sum=1;
    cin>>n>>k;
    vi a(n);
    tr(i,a) cin>>i;
    set<int> s;
    fr(i,n){
        int t=a[i],res=1;
        while(t>1) {
            int fac=pr[t],c=0;
            while(fac==pr[t]) t=t/pr[t],c++;
            if(c&1) res*=fac;
        }   
        if(s.find(res)!=s.end()) {
            sum++;
            s.clear();
        }
            s.insert(res);
            //cout<<res<<"x ";
    
    }
    cout<<sum<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    for(int i=2;i*i<=MAX;i++){
    if(pr[i]==1){
        for(int j=i*i;j<=MAX;j+=i) if(pr[j]==1) pr[j]=i;
    }
}
    for(int i=2;i<=MAX;i++){
        if(pr[i]==1) pr[i]=i;
    }
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}