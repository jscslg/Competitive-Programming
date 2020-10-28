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
    string s;
    cin>>s;
    int n=s.size(),res=0;
    string s1="KICK",s2="START";
    vi a,b;
    for(int i=0;i<n;){
        int j=0,k=i;
        if(i>0&&s[i-1]=='K'){
            j=1;   
            while(j<4 && s1[j]==s[i]) ++i,++j;
            if(j==4) a.pb(k);
        }
        else {
            while(j<4 && s1[j]==s[i]) ++i,++j;
            if(j==4) a.pb(k);
        }
        if(k==i) ++i;
    }
    for(int i=0;i<n;){
        int j=0,k=i;
        while(j<5 && s2[j]==s[i]) ++i,++j;
        if(j==5) b.pb(k);
        if(k==i) ++i;
    }
    int n1=a.size(),n2=b.size(),k=0,l=0;
    //tr(i,a) cout<<i<<" ";
    //tr(i,b) cout<<i<<" ";
    fr(i,n){
        if(k<n1 && a[k]==i) res+=n2-l,++k;
        else if(l<n2 && b[l]==i) ++l;
    }
    cout<<res<<endl;
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
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}