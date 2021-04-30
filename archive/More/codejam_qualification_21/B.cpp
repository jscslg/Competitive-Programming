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
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
//#define int ll
int MAX=1e5;

void solve(){
    int x,y,res=0;
    string s;
    cin>>x>>y>>s;
    int n=s.size();
    if(n==1){
        cout<<"0\n";
        return;
    }
    if(x>0 && y>0) {
        int i=0;
        while(i<n && s[i]==s[0]) i++; 
        while(i<n){
            char bef=s[i-1],ch=s[i];
            if(bef=='C' && ch=='J') res+=x;
            else if(bef=='J' && ch=='C') res+=y;
            while(i<n && s[i]==ch) i++;
            if(i==n) break;
            if(ch=='?' && bef!=s[i]){
                if(bef=='C') res+=x;
                else res+=y;
            }
        }
    }
    else if(x<0 && y<0){
        int i=0;
        while(i<n && s[i]==s[0]) i++;
        if(s[0]=='?'){
            if(i==n){
                if(i&1) res+=(i/2)*x+(i/2)*y;
                else res+=(min(x,y)*(i/2))+(max(x,y)*((i-1)/2));
            }
            else if(i%2==0) res+=(i/2)*x+(i/2)*y;
            else if(s[i]=='J') res+=((i+1)/2)*x+(i/2)*y;
            else if(s[i]=='C') res+=(i/2)*x+((i+1)/2)*y;
        }
        while(i<n){
            int c=0;
            char bef=s[i-1],ch=s[i];
            if(bef=='C' && ch=='J') res+=x;
            else if(bef=='J' && ch=='C') res+=y;
            while(i<n && s[i]==ch) i++,c++;
            if(ch=='?'){
                if(i==n){
                    if(bef=='C') res+=((c+1)/2)*x+(c/2)*y;
                    else res+=(c/2)*x+((c+1)/2)*y;
                }
                else if(bef==s[i]) res+=((c+1)/2)*x+((c+1)/2)*y;
                else if(bef=='C') res+=((c+2)/2)*x+(c/2)*y;
                else res+=(c/2)*x+((c+2)/2)*y;
            }
        }
    }
    else{
        int i=0;
        while(i<n && s[i]==s[0]) i++;
        if(s[0]=='?'){
            if(i==n){
                res+=min({x,y,(i/2)*x+((i-2)/2)*y,(i/2)*y+((i-2)/2)*x});
            }
            else if(s[i]=='J') res+=min({x,0,((i+1)/2)*x+(i/2)*y});
            else if(s[i]=='C') res+=min({y,0,((i+1)/2)*y+(i/2)*x});
        }
        while(i<n){
            int c=0;
            char bef=s[i-1],ch=s[i];
            if(bef=='C' && ch=='J') res+=x;
            else if(bef=='J' && ch=='C') res+=y;
            while(i<n && s[i]==ch) i++,c++;
            if(ch=='?'){
                if(i==n){
                    if(bef=='C') res+=min({x,0,((c+1)/2)*x+(c/2)*y});
                    else res+=min({y,0,((c+1)/2)*y+(c/2)*x});
                }
                else if(bef==s[i]) res+=min(0,((c+1)/2)*x+((c+1)/2)*y);
                else if(bef=='C') res+=min({x,((c+2)/2)*x+(c/2)*y});
                else if(bef=='J') res+=min({y,((c+2)/2)*y+(c/2)*x});
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
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}