// BEGIN CUT HERE

// END CUT HERE
#line 5 "EmoticonsDiv1.cpp"
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

const int inf = 1e9;
int dp[2010];

class EmoticonsDiv1
{
    public:
        int printSmiles(int n)
        {
            for(int i = 0; i <= 2 * n; i++) dp[i] = inf;
            dp[1] = 0;
            int cnt = 0;
            while(cnt++ < 2 * n)
            {
                for(int i = 1; i <= 2 * n; i++)
                {
                    if(i - 1 >= 0 && dp[i] + 1 < dp[i - 1])
                    {
                        dp[i - 1] = dp[i] + 1;
                    }
                    for(int j = 2; i * j <= 2 * n; j++)
                    {
                        dp[i * j] = min(dp[i] + j, dp[i * j]);
                    }
                }
            }

            return dp[n];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; verify_case(1, Arg1, printSmiles(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; verify_case(2, Arg1, printSmiles(Arg0)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 8; verify_case(4, Arg1, printSmiles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    EmoticonsDiv1 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
