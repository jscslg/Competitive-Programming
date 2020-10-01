ll po(ll num,ll p=MOD-2){
    ll res=1;
    while(p>0){
        if(p&1) res=(res*num)%MOD;
        p>>=1,num=(num*num)%MOD;
    }
    return res;
}
ll power(ll num,ll p){
    ll res=1;
    while(p>0){
        if(p&1) res*=num;
        p>>=1,num*=num;
    }
    return res;
}