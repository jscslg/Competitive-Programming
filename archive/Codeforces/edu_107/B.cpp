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
#define int ll
int MAX=1e5;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int n=1,s=1;
    while(s<c){
        n*=2;
        s=0;
        int t=n;
        while(t>0) t/=10,s++;
    }
    int na=n,nb=n;
    while(s<a){
        na*=3;
        s=0;
        int t=na;
        while(t>0) t/=10,s++;
    }
    s=c;
    while(s<b){
        nb*=5;
        s=0;
        int t=nb;
        while(t>0) t/=10,s++;
    }
    cout<<na<<" "<<nb<<"\n";
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