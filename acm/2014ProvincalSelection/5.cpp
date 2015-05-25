#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

int n,m;
int a[1000000];

bool ac(int x){
    int sum=0;
    for(int i=0;i<n;i++){
        int y=a[i]/x;
        if(y*x<a[i]) y++;
        sum+=y;
        if(sum>m) return false;
    }
    return true;
}
int solve(){
    int l=1,r=10000000;
    while(r-l>1){
        int mid=(l+r)/2;
        if(ac(mid)) r=mid;
        else l=mid;
    }
    if(ac(l)) return l;
    else return r;
}
int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(1){
        scanf("%d%d",&n,&m);
        if(n==-1) break;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",solve());
    }
    return 0;
}
