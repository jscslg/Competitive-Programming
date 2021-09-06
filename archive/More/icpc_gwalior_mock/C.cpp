/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using hmax=priority_queue<T>;
template<class T> using hmin=priority_queue<T,vector<T>,greater<T>>;
#define ll long long
#define ldb long double
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:(a))
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define ar(n) array<int,n>
#define ve vector
#define vi ve<int>
//#define int ll
const int MOD = 1000000007, MOD2 = 998244353;
const int MAX=1e5;
ve<ve<char>> res;
int n,m,x,y;

void fillr(int a,int b,char &ch){
    for(int j=a;j<y-1;j+=2){
        if(ch>='Z') ch='C';
        else ch++;
        res[x][j]=ch;
        res[x][j+1]=ch;
    }
    if((y-a)&1) res[x][y-1]=ch;
    for(int j=y+1;j<b;j+=2){
        if(ch>='Z') ch='C';
        else ch++;
        res[x][j]=ch;
        res[x][j+1]=ch;
    }
    if((b-y)&1) res[x][b]=ch;
}

void fill(int a,int c,int b,int d){
    char ch='C';
    fr(i,a,b+1){
        if(i==x) fillr(c,d,ch);
        else {
            for(int j=c;j<d;j+=2){
                if(ch>='Z') ch='C';
                else ch++;
                res[i][j]=ch;
                res[i][j+1]=ch;
            }
            if((d+1-c)&1) res[i][d]=ch;
        }
    }
}

void fillc(int x){
    char c='A';
    for(int i=0;i<n-1;i+=2){
        c=(c=='A'?'B':'A');
        res[i][x]=c,res[i+1][x]=c;
    }
    if(n&1) res[n-1][x]=c;
}

void fillr(int x){
    char ch='C';
        for(int j=0;j<n-1;j+=2){
                if(ch>='Z') ch='C';
                else ch++;
                res[x][j]=ch;
                res[x][j+1]=ch;
            }
            if((n)&1) res[x][n-1]=ch;
}

void solve(){
    cin>>n>>m>>x>>y,x--,y--;
    res=ve<ve<char>>(n,ve<char>(m));
    res[x][y]='*';
    if(y==m-2 || y==1){
        if(m==3){
            if(x==1&&y==1 && n==3 && m==3){
                cout<<"YES\nBCC\nB*D\nEED\n";
                return;
            }
            else{
            fillc(0);
            fillc(2);
            char ch='C';
            if(x==1) {
                fillr(0);
                fill(1,0,n-1,m-1);
            }
            else if(x==n-2) {
                fillr(n-1);
                fill(0,0,n-2,m-1);
            }
            else {for(int i=0;i<x-1;i+=2){
                if(ch>='Z') ch='C';
                else ch++;
                res[i][1]=ch;
                res[i+1][1]=ch;
            }
            if(x&1) res[x-1][1]=ch;
            for(int i=x+1;i<n-1;i+=2){
                if(ch>='Z') ch='C';
                else ch++;
                res[i][1]=ch;
                res[i+1][1]=ch;
            }
            if((n-x-1)&1) res[n-1][1]=ch;
            }
            }
        }
        else {
            if(y==1) fillc(0);
            else fillc(m-1);
            if(y==1) fill(0,1,n-1,m-1);
            else fill(0,0,n-1,m-2);
        }
    }
    else fill(0,0,n-1,m-1);
    cout<<"YES\n";
    tr(e,res) {
        tr(f,e) cout<<f;
        cout<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
        auto start = chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifdef LOCAL_JUDGE
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cerr << "Time taken : " << duration.count() / 1000000.0 << "seconds"<< "\n";
    #endif
    return 0;
}