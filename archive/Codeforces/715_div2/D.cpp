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

void solve(){
    int n;
    cin>>n;
    string a,b,c,x,y;
    ii aa,bb,cc;
    cin>>a>>b>>c;
    tr(e,a) (e=='1'?aa.F++:aa.S++);
    tr(e,b) (e=='1'?bb.F++:bb.S++);
    tr(e,c) (e=='1'?cc.F++:cc.S++);
    if(min(aa.F,bb.F)>=n || min(aa.S,bb.S)>=n) x=a,y=b;
    else if(min(aa.F,cc.F)>=n || min(aa.S,cc.S)>=n) x=a,y=c,bb=cc;
    else if(min(cc.F,bb.F)>=n || min(cc.S,bb.S)>=n) x=c,y=b,aa=cc;
    int mo=min(aa.F,bb.F),mz=min(aa.S,bb.S);
    if(mo>=n){
        if(aa.F<bb.F) swap(x,y),swap(aa,bb);
        int i=0,j=0,k=0;
        while(i<2*n&&j<2*n){
            int s=0;
            while(i<2*n&&x[i]!='1') cout<<0,i++,s++;
            while(j<2*n&&y[j]!='1') {
                if(s==0) cout<<0,j++;
                else s--;
            }
            cout<<1,k++,i++,j++;
        }
        while(i<2*n) cout<<x[i++];
        while(j<2*n) cout<<y[j++];
    }
    else {
        if(aa.S<bb.S) swap(x,y),swap(aa,bb);
        int i=0,j=0,k=0;
        while(i<2*n&&j<2*n){
            int s=0;
            while(i<2*n&&x[i]!='0') cout<<1,i++,s++;
            while(j<2*n&&y[j]!='0') {
                if(s==0) cout<<1,j++;
                else s--;
            }
            cout<<0,k++,i++,j++;
        }
        while(i<2*n) cout<<x[i++];
        while(j<2*n) cout<<y[j++];
    }
    cout<<"\n";
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