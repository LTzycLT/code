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

int sum,limit;
int a[100];
vector<int> ans;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d%d",&sum,&limit);
    for(int i=19;i>=0;i--){
        for(int j=0;;j++){
            int val =(j<<(i+1))+(1<<i);
            if(sum<(1<<i)||val>limit) break;
            ans.push_back(val);
            sum-=(1<<i);
        }
    }
    if(sum==0)
    {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    }else puts("-1");
    return 0;
}
