//~~~JsCode~~~
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
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
const int MAX=1e5+1;
vi p;
int find(int v){
    if(p[v]==v) return v;
    return p[v]=find(p[v]);
}
void un(int a,int b){
    p[a]=b;
}
void lead(int a){
    int x=find(a);
    p[x]=a,p[a]=a;
}

void solve(){
    int n,q,ch,a,b;
    cin>>n>>q;
    p.resize(n);
    fr(i,0,n) p[i]=i;
    while(q--){
        cin>>ch;
        if(ch==1) {
            cin>>a>>b;
            un(find(a-1),find(b-1));
        }
        else if(ch==2){
            cin>>a;
            lead(a-1);
        }
        else if(ch==3){
            cin>>a;
            cout<<p[a-1]+1<<endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}