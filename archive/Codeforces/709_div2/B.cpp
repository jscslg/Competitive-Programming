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
    int n,c=-1,m=0,d=0,mx=-1;
    cin>>n;
    vi a(n);
    tr(i,a) cin>>i,mx=max(mx,i);
    for(int i=1;i<n;i++){
        if(a[i]>=a[i-1]) {
            c=a[i]-a[i-1];
            break;
        }
    }
    if(c==-1){
        int i=1,f=0,d=a[1]-a[0];
        while(i<n && a[i]<a[i-1]) {
            if(a[i]-a[i-1]!=d){
                cout<<"-1\n";
                return;
            }
            i++;
        }
        cout<<"0\n";
        return;
    }
    for(int i=1;i<n;){
        if(a[i]>a[i-1]){
            while(i<n && a[i]>a[i-1]) {
                if(a[i]-a[i-1]!=c) {
                    cout<<"-1\n";
                    return;
                }
                i++;
            }
        }
        else if(a[i]<a[i-1]){
            if(m==0) m=a[i-1]+c-a[i];
            while(i<n && a[i]<a[i-1]) {
                if((a[i-1]+c)%m != a[i]){
                    cout<<"-1\n";
                    return;
                }
                i++;
            }
        }
        else{
            if(c!=0) {
                cout<<"-1\n";
                return;
            }
            i++;
        }
    }
    if(m==0) cout<<"0\n";
    else if(m<=mx) cout<<"-1\n";
    else cout<<m<<" "<<c<<"\n";
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