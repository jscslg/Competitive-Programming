#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,k=0,rev=0;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<ll> res(3*n,0);
        ll i=n-1,p=0,q=n-1;
        while(i>=0){
            if((rev%2==0&&a[q]!=b[i])||(rev%2==1&&a[q]==b[i])){
                if((rev%2==0&&a[p]==b[i])||(rev%2==1&&a[p]!=b[i])) res[k++]=1;
                res[k++]=i+1;
                ll c=p;
                p=q;
                if(rev%2==0) q=c+1;
                else q=c-1;
                rev++;
                i--;
            }
            else {
                i--;
                if(rev%2==0) q--; else q++;
            }
        }
        cout<<k;
        for(ll i=0;i<k;i++) cout<<" "<<res[i];
        cout<<endl;
    }
    return 0;
}