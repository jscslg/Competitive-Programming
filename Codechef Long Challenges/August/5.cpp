#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);++i)
#define f_(i,a,b) for(ll i=(a);i>=(b);--i)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 
int n,k;
vector<int> dp,a;

int get(int x){
    int sum=0,m=0;
    vector<int> freq(101,0);
    f(i,x,n) freq[a[i]]++;
    f(i,1,101) {
        if(freq[i]>1) sum+=freq[i];
        freq[i]=0;
    }
	m=sum, sum=0;
    f(i,x,n){
        freq[a[i]]++;
        if(freq[a[i]]>1) {
            int rec=-1;
            if(dp[i]!=-1) rec=dp[i];
            else rec=get(i),dp[i]=rec;
            if(rec!=-1 && rec<m-sum) {
                m=min(m,sum+rec);
            }
            sum+=(freq[a[i]]==2?2:1);
        }
    }
    return m+k;
}

int main() {
	fast;
	int t;
	cin>>t;
	while(t--){
	    int sum=0;
	    cin>>n>>k;
	    a.resize(n);
	    for(auto& i:a) cin>>i;
	    dp.resize(n,-1);
	    f(i,0,n) dp[i]=-1;
	    cout<<get(0)<<endl;
	}
	return 0;
}
