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
//#define int ll
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
    int n,sum=0,pos=0;
    cin>>n;
    vi x(n),t(n);
    fr(i,0,n) cin>>t[i]>>x[i];
    fr(i,0,n){
        int j=i+1,d=(x[i]>pos)?1:-1,end=t[i]+d*(x[i]-pos);
        if(j<n && t[j]<end) {
            //cout<<"x"<<t[i]+d*(x[i]-pos);
            while(j<n && t[j]<end){
                if(j==n-1){
                    if(d*x[j]>d*pos && d*x[j]<d*x[i]) sum++;
                    j++;
                    break;
                } 
                int st = pos+d*(t[j]-t[i]),en;
                if(d==1) en = min(x[i],pos+d*(t[j+1]-t[i]));
                else en = max(x[i],pos+d*(t[j+1]-t[i]));
                //cout<<time<<"x";
                if(d==1 && x[j]>=st && x[j]<=en) sum++;
                else if(d==-1 && x[j]<=st && x[j]>=en) sum++; 
                j++;
            }
        }
        else sum++;
        pos=x[i];
        i=j-1;
    }
    cout<<sum<<"\n";
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