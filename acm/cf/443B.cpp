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

char s[1000];
int n;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%s",s);
    int l = strlen(s);
    scanf("%d",&n);
    int ans = min(n,(n+l)/2);
    for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
            int len = j-i;
            if(j+len>l+n) continue;
            bool flag=true;
            for(int k=i+len;k<min(j+len,l);k++){
                if(s[k]!=s[k-len])
                    flag=false;
            }
            if(flag)
                ans = max(ans,len);
        }
    }
    printf("%d\n",2*ans);
    return 0;
}
