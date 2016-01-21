// BEGIN CUT HERE

// END CUT HERE
#line 5 "FencingPenguins.cpp"
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

class FencingPenguins
{
    public:
        int countWays(int numPosts, int radius, vector <int> x, vector <int> y, string color)
        {
            $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 10; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "R"; int Arg5 = 3; verify_case(0, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 10; int Arr2[] = {2,-2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "RR"; int Arg5 = 1; verify_case(1, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 10; int Arr2[] = {8,-8,-8,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,-1,1,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "BBBB"; int Arg5 = 25; verify_case(2, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 10; int Arr2[] = {8,-8,-8,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,-1,1,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "RGBY"; int Arg5 = 50; verify_case(3, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 6; int Arg1 = 5; int Arr2[] = {0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "rB"; int Arg5 = 6; verify_case(4, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 5; int Arr2[] = {4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "y"; int Arg5 = 0; verify_case(5, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 200; int Arg1 = 100000; int Arr2[] = {1020,30203,2302,203,-12321,-21332,8823,-2133,2323}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-123,2131,4434,1223,43434,2323,4343,-213,-2325}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arg4 = "YBYBWWBRr"; int Arg5 = 27547; verify_case(6, Arg5, countWays(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FencingPenguins ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
