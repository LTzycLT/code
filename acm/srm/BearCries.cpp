// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearCries.cpp"
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

ll dp[205][205][205];
ll mod = 1e9 + 7;
class BearCries
{
    public:
        int count(string s)
        {
            int n = s.length();
            clr(dp, 0);
            dp[0][0][0] = 1;
            for(int i = 1; i <= n; i++)
            {
                char ch = s[i - 1];
                for(int j = 0; j <= n; j++)
                {
                    for(int k = 0; k <= n; k++)
                    {
                        if(ch == ';')
                        {
                            if(k > 0)
                                dp[i][j][k] += dp[i - 1][j][k - 1];
                            if(j < n)
                                dp[i][j][k] += dp[i - 1][j + 1][k] * (j + 1);
                        }
                        else
                        {
                            if(j > 0 && k < n)
                                dp[i][j][k] += dp[i - 1][j - 1][k + 1] * (k + 1);
                            dp[i][j][k] += dp[i - 1][j][k] * j;
                        }
                        dp[i][j][k] %= mod;
                    }
                }
            }
            return dp[n][0][0];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ";_;;_____;"; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = ";;;___;;;"; int Arg1 = 36; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "_;__;"; int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = ";_____________________________________;"; int Arg1 = 1; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = ";__;____;"; int Arg1 = 0; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { string Arg0 = ";_;;__;_;;"; int Arg1 = 52; verify_case(5, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BearCries ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
