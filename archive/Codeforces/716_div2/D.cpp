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
int bl;

void solve(){
    int n,m;
    cin>>n>>m;
    vi a(n),freq(n,0),cnt(n,0);
    vii res(m);
    vector<iii> q(m);
    tr(e,a) cin>>e;
    fr(i,0,m) {
        q[i].F=i;
        cin>>q[i].S.F>>q[i].S.S,q[i].S.F--,q[i].S.S--;
    }
    bl=sqrt(n);
    sort(all(q),[](iii x,iii y){
        if(x.S.F/bl!=y.S.F/bl) return x.S.F/bl<y.S.F/bl;
        return x.S.S<y.S.S;
    });
    int s=0,cur=0,curl=1;
    fr(i,0,m){
        int l=q[i].S.F,r=q[i].S.S;
        while(cur < r){
			++cur;
			int val = a[cur],c = freq[val];
			cnt[c]--;
			freq[val]++;
			cnt[freq[val]]++;
			s = max(s, freq[val]);
		}
		while(curl > l){
			--curl;
			int val = a[curl],c = freq[val];
			cnt[c]--;
			freq[val]++;
			cnt[freq[val]]++;
			s = max(s, freq[val]);
		}
		while(cur > r){
			int val = a[cur],c = freq[val];
			cnt[c]--;
			freq[val]--;
			cnt[freq[val]]++;
			while(cnt[s] == 0)	s--;	
			--cur;
		}
		while(curl < l){
			int val = a[curl];
			cnt[freq[val]]--;
			freq[val]--;
			cnt[freq[val]]++;
			while(cnt[s] == 0)	s--;
			++curl;
		}
        res[q[i].F]={s,r-l+1};
    }
    fr(i,0,m){
        int sz=res[i].S,ot=sz-res[i].F,ans;
        if(res[i].F<=ot+1) ans=1;
        else ans=1+(res[i].F-(ot+1));
        cout<<ans<<"\n";
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