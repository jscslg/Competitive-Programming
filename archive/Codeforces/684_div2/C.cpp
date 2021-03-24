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
vii res;
int n,m;
char a[101][101];
int x[4]={0,0,1,1},y[4]={0,1,0,1};

void N3(int i,int j){
    fr(k,0,4){
        int c=x[k]+i,d=y[k]+j;
        if(a[c][d]=='1')  res.pb({c,d}),a[c][d]='0';
    }
}
void N1(int i,int j){
    int z=2;
    fr(k,0,4){
        int c=x[k]+i,d=y[k]+j;
        if(a[c][d]=='1') res.pb({c,d}),a[c][d]='0';
        else if(z){
            z--,res.pb({c,d});
            a[c][d]='1';
        }
    }
}
void N2(int i,int j){
    int o=1;
    fr(k,0,4){
        int c=x[k]+i,d=y[k]+j;
        if(a[c][d]=='1') {
            if(o) o=0,res.pb({c,d}),a[c][d]='0';
        }
        else res.pb({c,d}),a[c][d]='1';
    }
}
void N4(int i,int j){
    fr(k,0,3){
        int c=x[k]+i,d=y[k]+j;
        res.pb({c,d}),a[c][d]='0';
    }
}
int C(int i,int j){
    int n1=0;
    fr(k,0,4) {
        int c=x[k]+i,d=y[k]+j;
        if(a[c][d]=='1') n1++;
    }
    return n1;
}

int get(int i,int j){
    int n1=0;
    fr(k,0,4) {
        int c=x[k]+i,d=y[k]+j;
        if(a[c][d]=='1') n1++;
        //cout<<a[c][d];
    }
    if(n1==3){
        N3(i,j);
        return 1;
    }
    if(n1==2){
        N2(i,j);
        N3(i,j);
        return 2;
    }
    if(n1==1){
        N1(i,j);
        N2(i,j);
        N3(i,j);
        return 3;
    }
    else if(n1==4){
        N4(i,j);
        N1(i,j);
        N2(i,j);
        N3(i,j);
        return 4;
    }
    else return 0;
}

int get3(int i,int j){
    int n1=0,n2=0,n3=0;
    if(a[n-1][i]=='1') n3++;
    if(a[n-1][i+1]=='1') n3++;
    if(a[n-2][i]=='1') n2++;
    if(a[n-2][i+1]=='1') n2++;
    if(a[n-3][i]=='1') n1++;
    if(a[n-3][i+1]=='1') n1++;
    if(n1==0) return get(n-2,i);
    else if(n3==0) return get(n-3,i);
    else {
        if(n2+n1==1){
            if(n3==1){
                a[]
            }
        }
    }
}
void solve(){
    int sum=0;
    cin>>n>>m;
    res.clear();
    fr(i,0,n) fr(j,0,m) cin>>a[i][j];
    if(n%2==0&&m%2==0){
        for(int i=0;i<m-1;i+=2){
            for(int j=0;j<n-1;j+=2){
                sum+=get(j,i);
            }
        }
    }
    else if(n%2&&m%2){
        for(int i=0;i<m-3;i+=2){
            for(int j=0;j<n-3;j+=2){
                sum+=get(j,i);
            }
            get3(n-3,i);
        }

    if(n%2==1){
        for(int i=0,j=n-2;i<m-1;i+=2){
            sum+=get(j,i);
        }
    }
    if(m%2==1){
        for(int i=m-2,j=0;j<n-1;j+=2){
            sum+=get(j,i);
        }
    }
    if(n%2&&m%2){
        sum+=get(n-2,m-2);
    }
    }
    cout<<sum<<endl;
    for(int i=0;i<res.size();i+=3){
        cout<<res[i].F+1<<" "<<res[i].S+1<<" ";
        cout<<res[i+1].F+1<<" "<<res[i+1].S+1<<" ";
        cout<<res[i+2].F+1<<" "<<res[i+2].S+1<<"\n";
    }
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