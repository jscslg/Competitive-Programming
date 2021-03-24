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
    int a,b,mn;
    cin>>a>>b;
    int t=b;mn=a;
    if(a%b!=0){
        cout<<a<<endl;
        return;
    }
    int p=sqrt(b);
    vi d(p+2,0);
    fr(i,2,p+2){
        while(b%i==0){
            b/=i;
            d[i]++;
        }
    }
    fr(i,0,p+2){
        if(d[i]>0){
            int cnt=0,c=a,e=1;
            while(c%i==0){
                c/=i,cnt++;
            }
            while(cnt>=d[i]){
                e*=i,cnt--;
            }
            mn=min(e,mn);
        }
    }
    cout<<a/mn<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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