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
        f(j,8){
            f(k,8){
                if(j==0&&k==0) cout<<"O";
                else if (n>1){
                    cout<<".";
                    n--;
                }
                else cout<<"X";
            }
            cout<<endl;
        }
        cout<<endl;
    }
	return 0;
}
