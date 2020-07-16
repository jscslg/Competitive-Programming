#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,n)    for(ll (i)=0;(i)<n;(i)++)
#define f_(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define f_rev(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define in(n) ll n; cin>>n;
#define in_str(s) string s; cin>>s;
#define in_arr(x,n) ll x[n]; f(i,n) cin>>x[i];
#define fast ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);

using namespace std;

int main() {
    fast;
    in(t);
    f(i,t){
        in(n);
        ll n1=0,n2=0;
        f(j,n){
            ll x=0,y=0;
            in(a);
            in(b);
            while(a>0){
                x+= a%10;
                a= a/10;
            }
            while(b>0){
                y+= b%10;
                b= b/10;
            }
            if(x>y) n1++;
            else if(y>x) n2++;
            else {
                n1++;
                n2++;
            }
            
        }
        if(n1>n2) cout<<0<<" "<<n1<<endl;
        else if(n2>n1) cout<<1<<" "<<n2<<endl;
        else cout<<2<<" "<<n1<<endl;
    }
	return 0;
}
