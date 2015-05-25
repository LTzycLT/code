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

bool is[100000];
vector<int> pri;
int n;
int two[100000][2];
int three[100000][3],ans[100000];

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    is[1]=true;
    is[0]=true;
    for(int i=2;i<=20000;i++){
        if(!is[i]){
            for(int j=2;i*j<=20000;j++){
                is[i*j]=true;
            }
        }
    }
    for(int i=3;i<=20000;i++)
        if(!is[i])
            pri.push_back(i);
    for(int i=0;i<pri.size();i++){
        for(int j=0;j<pri.size()&&pri[i]+pri[j]<=20000;j++){
            if(i==j)
                two[pri[i]+pri[j]][1]++;
            two[pri[i]+pri[j]][0]++;
        }
    }
    for(int i=0;i<=20000;i++){
        for(int j=0;j<pri.size()&&i+pri[j]<=20000;j++)
            three[i+pri[j]][0]+=two[i][0];
    }
    for(int i=0;i<pri.size();i++){
        for(int j=0;j<pri.size()&&2*pri[i]+pri[j]<=20000;j++){
            if(i==j) continue;
            three[2*pri[i]+pri[j]][1]++;
//            if(2*pri[i]+pri[j]==11)
//                printf("%d %d\n",pri[i],pri[j]);
        }
    }
    for(int i=0;i<=20000;i++)
        if(i%3==0 && !is[i/3])
            three[i][2]=1;
    for(int i=0;i<=20000;i++){
        if(i%2==0) ans[i]=(two[i][0]-two[i][1])/2;
        else{
            ans[i]=(three[i][0]-3*three[i][1]-three[i][2])/6;
        }
    }
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",ans[n]);
    }
    return 0;
}
