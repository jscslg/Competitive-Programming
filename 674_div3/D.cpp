#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

void solve(){
    ll n;
    cin>>n;
    vi a(n);
    for(auto& i:a) cin>>i;
    ll i=0,cur,res=0;
    while(i<n){
        cur=0;
        unordered_map<ll,bool> m;
        while(i<n){
            
            cur+=a[i];
            if(cur==0 || m.find(cur)!=m.end()){
                res++;
                break;
            }
            m[cur]=1;
            ++i;
            //cout<<cur<<" ";
        }
        //cout<<endl;
    }
    cout<<res<<endl;
}

int main(){
    fast;
    //unordered_map<ll,bool> m;
    //m[-11]=1;
    //if(m.find(-11)!=m.end()) cout<<"AAWA";
    solve();
    return 0;
}