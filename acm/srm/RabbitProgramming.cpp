#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;
const double eps = 1e-6 ;

const int N = 55;
int mi[N],ma[N];
ll dp[N][N][N];
int n,p,q;

class RabbitProgramming
{
public:
    ll solve(){
        ll ans = 0;
        for(int x=1;x<=n;x++){
            clr(dp,0);
            dp[0][0][0] = 1;
            for(int i=1;i<=n;i++){
                if(i!=x){
                    for(int j=0;j<=n;j++){
                        for(int k=0;k<=n;k++){
                            if(i<x){
                                if(mi[i] < ma[x])
                                    dp[i][j][k] += dp[i-1][j][k];
                                else
                                    if(j>=1) dp[i][j][k] += dp[i-1][j-1][k];
                                if(ma[i]>=ma[x])
                                    if(j>=1&&k>=1) dp[i][j][k] += dp[i-1][j-1][k-1];
                            }
                            else{
                                if(mi[i]<=ma[x])
                                    dp[i][j][k] += dp[i-1][j][k];
                                else
                                    if(j>=1) dp[i][j][k] += dp[i-1][j-1][k];
                                if(ma[i]>ma[x])
                                    if(j>=1&&k>=1) dp[i][j][k] += dp[i-1][j-1][k-1];
                            }
                        }
                    }
                }
                else{
                    for(int j=1;j<=n;j++)
                        for(int k=1;k<=n;k++)
                            dp[i][j][k] = dp[i-1][j-1][k-1];
                }
            }
            for(int i=0;i<=p;i++)
                ans += dp[n][i][q];
        }
        return ans;
    }
	long long getTeams(vector <int> p, vector <string> s, int qu, int se){
        ::n = s.size();
        ::p = qu;
        ::q = se;
        clr(mi,0);clr(ma,0);
        for(int i=0;i<(int)p.size();i++){
            if(p[i]>0){
                for(int j=0;j<n;j++)
                    if(s[j][i]=='Y')
                        mi[j+1]+=p[i],ma[j+1]+=p[i];
            }
            else{
                for(int j=0;j<n;j++)
                    if(s[j][i]=='Y')
                        ma[j+1] += -p[i];
            }
        }
//        ::n = 2;
//        ::p = 2;
//        ::q = 1;
//        mi[1] = 6;ma[1] =10;
//        mi[2] = 1;ma[2] = 5;

		return solve();
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, -10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "NY",
  "YN",
  "YN",
  "YN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 2; long long Arg4 = 5LL; verify_case(0, Arg4, getTeams(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { -250, -500, -1000 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "YYY",
  "YNY",
  "YYN",
  "YYN",
  "YNN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 2; long long Arg4 = 10LL; verify_case(1, Arg4, getTeams(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 5, -12, 5, -15, 10, -20, 3, -25, 7, -32, 21, -45 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "YYYYYYYYYNYY",
  "YYYNYYYYYNNN",
  "YYYNYNYYNNYN",
  "YYYYYNYYYYNN",
  "YYNNYNYNYYNN",
  "YYYNNNYYNNNN",
  "YYNNNNYYNNNN",
  "NNYNYYYNYNNN",
  "NNNNNNYYYNNN",
  "YYYNNNYYYNNN" }
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 3; long long Arg4 = 99LL; verify_case(2, Arg4, getTeams(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	RabbitProgramming ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
