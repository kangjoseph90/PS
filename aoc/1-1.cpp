#include <cstdio>
#include <climits>
using namespace std;

int main(){

    int l=INT_MAX,t;
    int cnt=0;
    while(scanf("%d",&t)!=EOF){
        if(l<t) cnt++;
        l=t;
    }
    printf("%d",cnt);

}