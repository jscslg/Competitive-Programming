//simple sieve
for(int i=2;i*i<=MAX;i++){
    if(pr[i]){
        for(int j=i*i;j<=MAX;j+=i) pr[j]=0;
    }
}
//factorisation_sieve
for(int i=2;i*i<=MAX;i++){
    if(pr[i]==1){
        for(int j=i*i;j<=MAX;j+=i) if(pr[j]==1) pr[j]=i;
    }
}
//segmented_sieve
void sieve(ll l,ll r){
    int m=sqrt(r);
    vector<bool> temp(m+1,1),pr(r-l+1,1);
    for(int i=2;i*i<=m;i++){
        if(temp[i]){
            for(int j=i*i;j<=m;j+=i) temp[i]=0;
        }
    }
    for(int i=2;i<=m;i++){
        if(temp[i]){
            int x=l/i*i;
            if(x<l) x+=i;
            for(ll j=x;j<=r;j+=i) pr[j-l]=0;
        }
    }
}