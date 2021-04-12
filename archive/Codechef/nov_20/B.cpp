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
    int n,q,sum=0;
    cin>>n;
    vi a(n),b(n,0);
    tr(i,a) cin>>i;
    cin>>q;
    fr(i,0,n){
        if(i==0) {
            if(a[i]==1){
                tr(e,b) e=1;
                sum=1;
                break;
            }
            b[i]=a[i];
            if(n==1) sum=(a[i]%2?a[i]:a[i]-1)%MOD;
            else if(n==2&&a[i+1]==1){
                sum=((a[i]%2?a[i]-1:a[i])+1)%MOD;
                b[i+1]=sum;
                i++;
            }
            else if(a[i+1]==1){
                b[i+1]=((a[i]%2?a[i]-1:a[i])+1)%MOD;
                sum=(a[i]%2?a[i]:a[i]-1)%MOD;
                i++;
            }
            else sum=(a[i]%2?a[i]-1:a[i])%MOD;
        }
        else{
            b[i]=(sum+a[i])%MOD;
            if(i<n-2&&a[i+1]==1){
                b[i+1]=(sum+(a[i]%2?a[i]-1:a[i])+1)%MOD;
                sum+=(a[i]%2?a[i]:a[i]-1);
                i++;
            }
            if(i==n-2&&a[i+1]==1){
                sum+=(a[i]%2?a[i]-1:a[i])+1;
                b[i+1]=sum%MOD;
                i++;
            }
            else if(i==n-1) sum+=(a[i]%2?a[i]:a[i]-1);
            else sum+=(a[i]%2?a[i]-1:a[i]);
            sum%=MOD;
        }
    }
    while(q--){
        int r;
        cin>>r;
        int x=(r-1)/n,y=(r-1)%n,res;
        res=((((x%MOD)*sum)%MOD)+b[y])%MOD;
        if(a[0]==1&&n>1&&y==0&&x>0) --res;
        cout<<res<<endl;
    }
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