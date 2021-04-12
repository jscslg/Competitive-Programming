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
    string s;
    cin>>s;
    int n=s.size();
    bool f=0;
    fr(i,0,n){
        if(s[i]!='a') f=1;
    }
    if(!f) {
        cout<<"NO\n";
        return;
    }
    int i=0,j=n-1;
    while(i<n && s[i]=='a') i++;
    while(j>=0 && s[j]=='a') j--;
    j=n-j-1;
    if(i-j==1) cout<<"YES\na"<<s<<"\n";
    else cout<<"YES\n"<<s<<"a\n";
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