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
    string s;
    cin>>s;
    int n=s.size(),zero=0,one=0;
    tr(i,s) (i=='0')? zero=1:one=1;
    if(!zero || !one){
        cout<<(!zero?"0":"1")<<"\n";
        return;
    }
    vi p(n,0);
    int c=s[n-1]-'0',j=0;
    frv(i,n-1,0){
        p[i]=j/2;
        if(s[i]-'0'==c%2){
            c++,j++;
            if(j%2==0 && i) c=s[i-1]-'0';
        }
    }
    //fr(i,0,n) cout<<p[i]<<" ";
    int i=0;
    while(i<n && s[i]!='1') i++;
    if(i==n-1){
        cout<<"10\n";
        return;
    }
    cout<<"1";
    int sz=p[i]+1;
    fr(k,i+1,n){
        if(p[k]==sz-1){
            int ch=(s[k]-'0'+1)%2;
            cout<<ch;
            while(k<n && s[k]-'0'!=ch) k++;
            sz--;
        } 
        else if(p[k]<sz-1){
            cout<<"0";
            while(k<n && s[k]!='0') k++;
            sz--;
        }
        else break;
    }
    fr(k,0,sz) cout<<"0";
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