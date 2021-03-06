// BEGIN CUT HERE

// END CUT HERE
#line 5 "SumOverPermutations.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

const ll mod = 1e9+7;
ll c[4005][4005];
ll dp[4005][2][2];
ll x;


ll dfs(int n, int l, int r)
{
    if(n == 0) return 1;
    if(n == 1) return x - l - r;
    if(dp[n][l][r] != -1) return dp[n][l][r];
    dp[n][l][r] = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == 0) dp[n][l][r] += (x - l) * dfs(n - 1, 1, r);
        else if(i == n - 1) dp[n][l][r] += (x - r) * dfs(n - 1, l, 1);
        else
        {
            dp[n][l][r] += x * dfs(i, l, 1) % mod * dfs(n - i - 1, 1, r) % mod * c[n - 1][i] % mod;
        }
        if(dp[n][l][r] >= mod) dp[n][l][r] %= mod;
    }
    return dp[n][l][r];
}
class SumOverPermutations
{
    public:
        int findSum(int n)
        {
            x = n;
            c[0][0] = 1;
            for(int i = 1; i <= n; i++)
            {
                c[i][0] = c[i][i] = 1;
                for(int j = 1; j < i; j++)
                {
                    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod; 
                }
            }
            for(int i = 0; i <= n; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) dp[i][j][k] = -1;
            return dfs(n, 0, 0);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; verify_case(0, Arg1, findSum(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 66; verify_case(1, Arg1, findSum(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 58310114; verify_case(2, Arg1, findSum(Arg0)); }
	void test_case_3() { int Arg0 = 3900; int Arg1 = 940560814; verify_case(3, Arg1, findSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SumOverPermutations ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
