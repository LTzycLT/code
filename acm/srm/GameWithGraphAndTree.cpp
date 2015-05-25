#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define INC(x,y) x = (x+y)%mod;
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;
const double eps = 1e-6 ;

const ll mod = 1000000007;
int dp[15][15][1<<14];
int p[15][1<<14];
int g[20][20],t[20][20];
int n;

class GameWithGraphAndTree
{
public:
    void dfs(int u,int f){
        int fb = 0;
        for(int v=0;v<n;v++){
            if(!t[u][v] || v==f) continue;
            dfs(v,u);
            if(fb == 0){
                fb = 1;
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        if(g[i][j])
                        for(int k=0;k<(1<<n);k++)
                            if(((k>>i)&1)==0){
                                INC(dp[u][i][k|(1<<i)],dp[v][j][k]);
                            }
            }
            else{
                clr(p,0);
                for(int i=0;i<n;i++)
                    for(int k=0;k<(1<<n);k++)
                    if(((k>>i)&1) && dp[u][i][k])
                        for(int j=0;j<n;j++)
                        if(g[i][j]){
                            int rt = (1<<n)-1-k;
                            for(int l=rt;l>0;l=(l-1)&rt){
                                if((l>>j)&1){
                                    INC(p[i][k|l] , dp[u][i][k] * dp[v][j][l]);
                                }
                            }
                        }
                for(int i=0;i<n;i++) for(int j=0;j<(1<<n);j++) dp[u][i][j] = p[i][j];
            }
        }
        if(fb==0){
            for(int i=0;i<n;i++) dp[u][i][1<<i] = 1;
        }
    }
	int calc(vector <string> g, vector <string> t){
        n = g.size();
        clr(dp,0);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(g[i][j]=='Y') ::g[i][j] = 1;
                else ::g[i][j] = 0;
                if(t[i][j]=='Y') ::t[i][j] = 1;
                else ::t[i][j] = 0;
            }
        dfs(0,0);
        int ans = 0;
        for(int i=0;i<n;i++) for(int j=0;j<(1<<n);j++) ans = (ans+dp[0][i][j])%mod;
		return  ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY",
 "YNN",
 "YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYNNN",
 "YNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNN",
 "YNYNN",
 "NYNYN",
 "NNYNY",
 "NNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNNY",
 "YNYNNN",
 "NYNYNN",
 "NNYNYN",
 "NNNYNY",
 "YNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNYN",
 "YNNYNY",
 "NNNNYN",
 "NYNNNN",
 "YNYNNN",
 "NYNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NYNNYN",
 "YNNYNY",
 "NNNNYN",
 "NYNNNN",
 "YNYNNN",
 "NYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNYYN",
 "NNYNNN",
 "NYNNYY",
 "YNNNNN",
 "YNYNNN",
 "NNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNYNNY",
 "YNNNNNNYN",
 "NNNNYYNYY",
 "NNNNNYNNY",
 "NNYNNNYNY",
 "YNYYNNNYN",
 "NNNNYNNYN",
 "NYYNNYYNN",
 "YNYYYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYNNNYYN",
 "NNNNYNNNN",
 "YNNNNNNNN",
 "NNNNNNYNN",
 "NYNNNNNYY",
 "NNNNNNNNY",
 "YNNYNNNNN",
 "YNNNYNNNN",
 "NNNNYYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 90; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	GameWithGraphAndTree ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
