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
#define tr(i,a) for(auto& i:a)
#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1;

void solve(){
    int n,w,z;
    cin>>n>>w;
    vii a(n);
    fr(i,0,n) {
        cin>>z;
        a[i]={z,i};
    }
    sort(all(a));
    vi f(n,0);
    int l=0,r=0,x=ceil(w/2.0),sum=0;
    while(r<n&&r>=l){
        if(sum<x){
            sum+=a[r].F,f[a[r].S]=1,r++;
        }
        else if(sum>w){
            sum-=a[l].F,f[a[l].S]=0,l++;
        }
        if(sum>=x&&sum<=w){
            cout<<r-l<<"\n";
            fr(i,0,n) if(f[i]) cout<<i+1<<" ";
            cout<<"\n";
            return;
        }
    }
    while(r>=l){
        if(sum>w){
            sum-=a[l].F,f[a[l].S]=0,l++;
        }
        else break;
        if(sum>=x&&sum<=w){
            cout<<r-l<<"\n";
            fr(i,0,n) if(f[i]) cout<<i+1<<" ";
            cout<<"\n";
            return;
        }
    }
    cout<<"-1\n";
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