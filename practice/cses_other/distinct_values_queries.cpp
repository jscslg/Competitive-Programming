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
int MAX=1e5+1;
vi a;
vector<pair<ii,int>> q;
int bl=555;

bool cmp(pair<ii,int> a,pair<ii,int> b){
    if(a.F.F/bl==b.F.F/bl) return a.F.S<b.F.S;
    return a.F.F/bl<b.F.S/bl;
}

void solve(){
    int n,m,cur=1;
    cin>>n>>m;
    a.resize(n);
    q.resize(m);
    vi res(m);
    map<int,int> d;
    tr(e,a) {
        cin>>e;
        if(d.find(e)!=d.end()) e=d[e];
        else d[e]=cur,e=cur++;
    }
    fr(i,0,m) cin>>q[i].F.F>>q[i].F.S,q[i].S=i,q[i].F.F--,q[i].F.S--;
    sort(all(q),cmp);
    vi f(2e5+1,0);
    int l=q[0].F.F,r=l,sum=1;
    f[a[l]]++;
    tr(e,q){
        int nl=e.F.F,nr=e.F.S;
        while(l>nl){
            l--;
            if(!f[a[l]]) sum++;
            f[a[l]]++;
        }
        while(r<nr){
            r++;
            if(!f[a[r]]) sum++;
            f[a[r]]++;
        }
        while(l<nl){
            f[a[l]]--;
            if(!f[a[l]]) sum--;
            l++;
        }
        while(r>nr){
            f[a[r]]--;
            if(!f[a[r]]) sum--;
            r--;
        }
        res[e.S]=sum;
    }
    tr(e,res) cout<<e<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}