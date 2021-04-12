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

int g(char c){
    return c=='1';
}

void solve(){
    int n;
    string a,b;
    cin>>n>>a>>b;
    int a1=0,a0=0,c=0;
    fr(i,0,n) (a[i]=='1'?a1++:a0++);
    frv(i,n-1,0){
        int x=(g(a[i])+c)%2,y=g(b[i]);
        if(x!=y) {
            if(a1!=a0){
                cout<<"NO\n";
                return;
            }
            c++;
            swap(a1,a0);
        }
        if((g(a[i])+c)%2==1) a1--;
        else a0--;
    }
    cout<<"YES\n";
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