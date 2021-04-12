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
#define int ll
int MAX=1e5;
int n,m,res=0;

void calc(int x,int y){
    fr(i,x,n) res+=min(m-y,n-i);
}

void solve(){
    res=0;
    int k,ln=-1,un=-1;
    cin>>n>>m>>k;
    vvi a(n,vi(m));
    tr(i,a) tr(j,i) cin>>j,j-=k;
    vvi s=a;
    fr(i,0,n) fr(j,1,m) s[i][j] += s[i][j-1];
    fr(i,0,m) fr(j,1,n) s[j][i] += s[j-1][i];
    fr(i,0,m) {
        fr(j,0,n) {
            if(a[j][i]>=0) {
                calc(j,i);
                break;
            }
        }
    }
    //cout<<res<<" ";
    fr(i,0,n) if(a[i][0]<0) ln=i;
    fr(i,1,m) if(a[0][i]<0) un=i;

    if(ln!=-1){
        fr(i,0,ln+1){
            int lx=i,ly=0,rx=i,ry=0;
            for(int j=i+1,k=1;j<n && k<m;j++,k++) {
                if(a[j][k]>=0) {
                    lx=j-1,ly=k-1,rx=j,ry=k;
                    break;
                }
            }
            if(lx==rx) continue;
            int sum=0;
            while(lx>=0 && rx<n && ly>=0 && ry<m){
                while(rx<n && ry<m){
                    sum=s[rx][ry];
                    if(lx) sum-=s[lx-1][ry];
                    if(ly) sum-=s[rx][ly-1];
                    if(lx && ly) sum+=s[lx-1][ly-1];
                    //cout<<sum<<" ";
                    if(sum>=0){
                        res+=min(n-rx,m-ry),lx--,ly--;
                        break;
                    }
                    rx++,ry++;
                }
            }
        }
    }
    if(un!=-1){
        fr(i,1,un+1){
            int lx=0,ly=i,rx=0,ry=i;
            for(int j=1,k=i+1;j<n && k<m;j++,k++) {
                if(a[j][k]>=0) {
                    lx=j-1,ly=k-1,rx=j,ry=k;
                    break;
                }
            }
            if(lx==rx) continue;
            int sum=0;
            while(lx>=0 && rx<n && ly>=0 && ry<m){
                while(rx<n && ry<m){
                    sum=s[rx][ry];
                    if(lx) sum-=s[lx-1][ry];
                    if(ly) sum-=s[rx][ly-1];
                    if(lx && ly) sum+=s[lx-1][ly-1];
                    //cout<<sum<<" ";
                    if(sum>=0){
                        res+=min(n-rx,m-ry),lx--,ly--;
                        break;
                    }
                    rx++,ry++;
                }
            }
        }
    }
    cout<<res<<"\n";
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