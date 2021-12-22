#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double

double A,B,C;

double Tau=6.2831853071795864768;

double sin_(double x){
    x+=Tau;
    x=x-Tau*(int)(x/Tau);
    double ret=0;
    for(int i=0;i<500;i++){
        double now=(i%2==0?1:-1);
        for(double j=1;j<=i*2+1;j++){
            now*=x;
            now/=j;
        }
        ret+=now;
    }
    return ret;
}
double f(double x){
    //cout<<sin(x)<<' '<<sin_(x)<<endl;
    return A*x+B*sin_(x)-C;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cout<<fixed;
    cout.precision(6);

    cin>>A>>B>>C;
    
    //f(x)=Ax+Bsin(x)-C

    double s=0,e=200000,m;
    while(e-s>1e-9){
        m=(s+e)/2;
        double now=f(m);
        //cout<<m<<"-------"<<now<<endl;
        if(now>0) e=m+1e-10;
        else if(now<0) s=m-1e-10;
        else break;
    }
    cout<<m<<endl;

}