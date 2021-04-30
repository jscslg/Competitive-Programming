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

vi digits(int t){
    vi d;
    while(t>0){
        d.pb(t%10);
        t/=10;
    }
    reverse(all(d));
    return d;
}
int num(vi d){
    int t=0;
    tr(e,d) t=t*10ll+e;
    return t;
}

void solve(){
    int n,res=0;
    cin>>n;
    vi a(n);
    tr(e,a) cin>>e;
    vi cur=digits(a[0]);
    fr(j,1,n){
        vi t=digits(a[j]);
        bool f=1;
        if(cur.size()<t.size()) f=0;
        else if(cur.size()==t.size()){
            fr(i,0,cur.size()) {
                if(cur[i]==t[i]) continue;
                f=cur[i]>t[i];
                break;
            }
        }
        if(f){
            //vi t1=digits(cur),t2=digits(a[j]);
            if(cur.size()==t.size()) t.pb(0),cur=t;
            else {
                int i=0;
                while(i<t.size() && cur[i]==t[i]) i++;
                if(i==t.size()) {
                    bool fl=0;
                    frv(k,cur.size()-1,i){
                        if(cur[k]!=9) {
                            cur[k]++;
                            fr(l,k+1,cur.size()) cur[l]=0;
                            fl=1;
                            break;
                        }
                    }
                    if(!fl){
                        int x=cur.size()-t.size()+1;
                        fr(k,0,x) t.pb(0);
                        cur=t;
                    }
                }
                else{
                    int x=cur.size()-t.size();
                    fr(k,0,x) t.pb(0);
                    if(t[i]<cur[i]) t.pb(0);
                    cur=t;
                }
            }
            res+=cur.size()-digits(a[j]).size();
        }
        else cur=t;
    }
    cout<<res<<"\n";
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