#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
//#define int ll
#define MOD 1000000007
#define fr(i,a,b) for(int i=(a);i<(b);++i)
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
#define INIT 1
const int MAX=1e5+1;
vector<bool> pr(MAX,1);
void initialize(){
    pr[0]=0;
    for(int i=2;i*i<=MAX;i++){
        if(pr[i]) for(int j=i*i;j<=MAX;j+=i) pr[j]=0;
    }
}

void solve(){
    int d,p,a,b,maxp;
    cin>>d;
    if(d<=4){
        if(d==0) cout<<"1\n1\n";
        else if(d==1) cout<<"2\n3 2\n";
        else if(d==2) cout<<"2\n5 3\n";
        else if(d==3) cout<<"2\n7 4\n";
        else if(d==4) cout<<"2\n7 5\n";
        return;
    }
    fr(i,min(d,MAX),100) if(pr[i]) p=i;
    maxp=p,p--;
    a=d/(p-1),b=d%(p-1);
    //a=d/(p-1),b=d%(p-1);
    //cout<<b;
    if(b==0){
        cout<<a+1<<endl;
        fr(i,0,a) cout<<p<<" ";
        cout<<maxp<<" ";
        cout<<endl;
        return;
    }
    cout<<a+3<<endl;
    fr(i,0,a) cout<<p<<" ";
    cout<<maxp<<" 1 "<<maxp<<" "<<b+1<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}