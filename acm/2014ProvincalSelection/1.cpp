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

int n;
int a[1000],b[1000],c[1000];

vector<int> get(int num){
    vector<int> x;
    while(num){
        x.push_back(num%10);
        num/=10;
    }
    return x;
}
int same(vector<int> a,vector<int> b){
    int x[10],y[10];
    clr(x,0);
    clr(y,0);
    for(int i=0;i<4;i++) x[a[i]]++;
    for(int i=0;i<4;i++) y[b[i]]++;
    int res=0;
    for(int i=0;i<10;i++)
        res+=min(x[i],y[i]);
    return res;
}
int right(vector<int> a,vector<int> b){
    int res=0;
    for(int i=0;i<4;i++)
        if(a[i]==b[i])
            res++;
    return res;
}
int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int num=0;
        for(int i=1000;i<=9999;i++){
            vector<int> x=get(i);
            bool flag=true;
            for(int j=0;j<n;j++){
                vector<int> y=get(a[j]);
                if(same(x,y)!=b[j] || right(x,y)!=c[j])
                    flag=false;
            }
            if(flag){
                if(num==0) num=i;
                else num=-1;
            }
        }
        if(num<=0) puts("Not sure");
        else printf("%d\n",num);
    }
    return 0;
}
