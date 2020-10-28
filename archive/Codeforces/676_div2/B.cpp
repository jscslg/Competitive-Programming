#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
//#define int ll
#define MOD 1000000007
#define fr(i,a) for(int i=0;i<(a);++i)
#define tr(i,a) for(auto& i:a)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define INIT 0
const int MAX=1e6;
void initialize(){}

void solve(){
    int n;
    cin>>n;
    vector<string> a(n);
    fr(i,n) cin>>a[i];
    char x=a[0][1],y=a[1][0],c=a[n-1][n-2],d=a[n-2][n-1];
    if(x==y){
        if(c==x){
            if(d==x){
                cout<<2<<endl<<n<<" "<<n-1<<endl<<n-1<<" "<<n<<endl;
                return;
            }
            cout<<1<<endl<<n<<" "<<n-1<<endl;
            return;
        }
        else if(d==x){
            cout<<1<<endl<<n-1<<" "<<n<<endl;
            return;
        }
        cout<<0<<endl;
    }
    else{
        if(c==d){
            if(x!=c) cout<<"1\n2 1\n";
            else if(y!=d) cout<<"1\n1 2\n";
        }
        else {
            if(x==c) cout<<"2\n2 1\n"<<n<<" "<<n-1<<endl;
            else cout<<"2\n2 1 \n"<<n-1<<" "<<n<<endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}