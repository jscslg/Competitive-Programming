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
int MIN=-1e18,MAX=1e18;
int q,d;

string askp(int a,int b){
    string res;
    cout<<"1 "<<a<<" "<<b<<endl;
    cin>>res;
    return res;
}

int askr(int a,int b,int c,int e){
    string res;
    cout<<"2 "<<a<<" "<<b<<" "<<c<<" "<<e<<endl;
    cin>>res;
    if(res=="IN") return 1;
    if(res=="O") return 0;
    return -1;
}

void solve4x3(int xl,int xr,int yl,int yr){
    int a1=askr(xl,yl+1,xr,yr);
    if(a1==0) return;
    else if(a1==-1){
        int a2=askr(xl,yl-1,xr,yl+1);
    }
    else{
        int a2=askr(xl,yl+1,xr,yr);
    }
}

void solve3x4(int xl,int xr,int yl,int yr){
    int a1=askr(xl+1,yl,xr,yr);
    if(a1==0) return;
    else if(a1==-1){
        int a2=askr(xl-1,yl,xl+1,yr);
    }
    else{
        int a2=askr(xl+1,yl,xr,yr);
    }
}

void solve(){
    int xl=MIN,xr=MAX,yl=MIN,yr=MAX;
    if(d==0) {
        while(xl<xr || yl<yr){
            int xm=xl+(xr-xl+1)/2,ym=yl+(yr-yl+1)/2;
            string res=askp(xm,ym);
            if(res=="O") return;
            if(res[0]=='X') xl=xm,xr=xm;
            else if(res[0]=='P') xr=xm-1;
            else xl=xm;
            if(res[1]=='Y') yl=ym,yr=ym;
            else if(res[1]=='P') yr=ym-1;
            else yl=ym;
        }
    }
    else{
        while(xr-xl>3 || yr-yl>3){
            int xm=xl+(xr-xl+1)/2,ym=yl+(yr-yl+1)/2;
            string res=askp(xm,ym);
            if(res=="O") return;
            if(res[0]=='X') xl=xm,xr=xm;
            else if(res[0]=='P') xr=xm-1;
            else xl=xm+1;
            if(res[1]=='Y') yl=ym,yr=ym;
            else if(res[1]=='P') yr=ym-1;
            else yl=ym+1;
            yl--,yr++,xl--,xr++;
            //cout<<yl<<" "<<yr<<" "<<xl<<" "<<xr<<"\n";
        }
        if(xr-xl==3 && yr-yl==3){
            int a1=askr(xl+1,yl,xr,yr);
            if(a1==0) return;
            else if(a1==1) solve4x3(xl+1,xr,yl,yr);
            else solve4x3(xl-1,xl+1,yl,yr);
        }
        else if(xr-xl==2 && yr-yl==2){
            int a1=askr(xl,yl,xr,yr);
            if(a1==0) return;
            int a2=askr(xl,yl,xr,yr);
        }
        else if(yr-yl==2){
            solve3x4(xl,xr,yl,yr);
        }
        else if(xr-xl==2){
            solve4x3(xl,xr,yl,yr);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //#ifdef LOCAL_JUDGE
    //freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    //#endif
    //INIT
    int t=1;
    cin>>t>>q>>d;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}