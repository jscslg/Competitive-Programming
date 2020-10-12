#include <bits/stdc++.h>
#define ll long long
#define ldb long double
#define MOD 1000000007
#define any_data int
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<any_data>
#define vvi vector<vi>
#define ii pair<any_data,any_data>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
void c_p_c(){ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout); }
const int mx=1e5+1;

void solve(){
    int n;
    cin>>n;
    int p=2,c=0;
    while(p<=n){
        if(p==n) {
            cout<<"-1\n";
            return;
        }
        p*=2,c++;
    }
    if(n==1) {
        cout<<"1\n";
        return;
    }
    if(n==3) {
        cout<<"2 3 1\n";
        return;
    }
    cout<<"2 3 1 ";
    f(i,2,c){
        int m=(1<<i)+1;
        f(j,0,(1<<i)-2) cout<<m+j<<" ";
        cout<<(1<<i)<<" "<<((1<<i+1)-1)<<" ";
    }
    int m=(1<<c)+1;
    f(i,0,n-(1<<c)) cout<<m+i<<" ";
    cout<<(1<<c)<<"\n";
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    c_p_c();
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}