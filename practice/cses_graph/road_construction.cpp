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
int n,m;
struct node{
    int r,s,p;
    node(){}
    node(int a,int b,int c){
        p=a,r=b,s=c;
    }
};
vector<node> p;
int num,sz=1;

int find(int a){
    if(p[a].p==a) return a;
    p[a].p= find(p[a].p);
    return p[a].p;
}

void unison(int a,int b){
    if(p[a].r>p[b].r) p[b].p=a,p[a].s+=p[b].s,sz=max(sz,p[a].s);
    else if(p[a].r<p[b].r) p[a].p=b,p[b].s+=p[a].s,sz=max(sz,p[b].s);
    else{
        p[a].p=b;
        p[b].r++;
        p[b].s+=p[a].s;
        sz=max(sz,p[b].s);
    }
}

void solve(){
    cin>>n>>m;
    num=n;
    p.resize(n);
    fr(i,0,n) p[i]=node(i,0,1);
    fr(i,0,m){
        int a,b;
        cin>>a>>b,a--,b--;
        int x=find(a),y=find(b);
        if(x!=y) {
            num--;
            unison(x,y);
        }
        cout<<num<<" "<<sz<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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