#include <bits/stdc++.h>
#define ll long long
#define ldb long double
#define MOD 1000000007
#define any_data int
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<any_data>
#define vvi vector<vi>
#define ii pair<any_data,any_data>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
void c_p_c(){ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout); }
const int mx=1e6;

void solve(){
    vector<vector<char>> a(3,vector<char>(3));
    int nx=0,no=0;
    f(i,0,3) {
        f(j,0,3) {
            cin>>a[i][j];
            if(a[i][j]=='X') nx++;
            else if(a[i][j]=='0') no++;
        }
    }
    //cout<<no<<" "<<nx;
    if(!(no==nx||nx==no+1)) {
        cout<<"illegal"<<endl;
        return;
    }   
    int x=0,o=0;
    f(i,0,3){
        bool tx=1,to=1;
        f(j,0,3){
            if(a[i][j]!='X') tx=0;
            if(a[i][j]!='0') to=0;
        }
        if(tx) x++;
        if(to) o++;
    }
    f(j,0,3){
        bool tx=1,to=1;
        f(i,0,3){
            if(a[i][j]!='X') tx=0;
            if(a[i][j]!='0') to=0;
        }
        if(tx) x++;
        if(to) o++;
    }
    int i=0,j=0;
    bool tx=1,to=1;
    while(i<3&&j<3){
        if(a[i][j]!='X') tx=0;
        if(a[i][j]!='0') to=0;
        i++,j++;
    }
    if(tx) x++;
    if(to) o++;

    i=0,j=2;
    tx=1,to=1;
    while(i<3&&j>=0){
        if(a[i][j]!='X') tx=0;
        if(a[i][j]!='0') to=0;
        i++,j--;
    }
    if(tx) x++;
    if(to) o++;

    if(x+o>0){
        if(x>0&&o>0) cout<<"illegal"<<endl;
        else if(x>=1) {
            if(nx==no+1) cout<<"the first player won"<<endl;
            else cout<<"illegal"<<endl;
        }
        else if(o>=1) {
            if(nx==no) cout<<"the second player won"<<endl;
            else cout<<"illegal"<<endl;
        }
        return;
    }
    if(nx+no==9) cout<<"draw";
    else if(nx==no) cout<<"first"<<endl;
    else if(nx==no+1) cout<<"second"<<endl;
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    c_p_c();
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}