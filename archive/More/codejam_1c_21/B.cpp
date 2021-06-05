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

bool check(int n){
    int t=n,d=0;
    while(t>0) t/=10,d++;
    fr(i,1,d/2+1){
        int e=d,j=i,s=n/((int)pow(10,e-j));
        bool fl=1;
        e-=j,t=n%((int)pow(10,e)),s++;
        if(s==pow(10,j)) j++;
        while(e>=j){
            if(t/((int)pow(10,e-j))!=s) {
                fl=0;
                break;
            }
            e-=j,t=t%((int)pow(10,e)),s++;
            if(s==pow(10,j)) j++;
        }
        if(e==0&&fl) return 1;
    }
    return 0;
}

void solve(){
    int n;
    cin>>n;
    fr(i,n+1,1234568){
        if(check(i)) {
            cout<<i<<"\n";
            return;
        }
    }
    cout<<"100101\n";
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
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}