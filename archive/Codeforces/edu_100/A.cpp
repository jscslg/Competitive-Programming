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

    void solve(){
        vi a(3);
        int m=1e9,c=0,sum=0;
        fr(i,0,3) cin>>a[i],m=min(m,a[i]),sum+=a[i];
        if(sum%9==0 && sum>8 && m>=sum/9) cout<<"YES\n";
        else cout<<"NO\n";
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