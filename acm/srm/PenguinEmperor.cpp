// BEGIN CUT HERE

// END CUT HERE
#line 5 "PenguinEmperor.cpp"
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

class PenguinEmperor
{
    public:
        int countJourneys(int numCities, long long daysPassed)
        {
            $CARETPOSITION$
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 2LL; int Arg2 = 2; verify_case(0, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 3LL; int Arg2 = 2; verify_case(1, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 36LL; int Arg2 = 107374182; verify_case(2, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 300; long long Arg1 = 751LL; int Arg2 = 413521250; verify_case(3, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 300; long long Arg1 = 750LL; int Arg2 = 0; verify_case(4, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 350; long long Arg1 = 1000000000000000000LL; int Arg2 = 667009739; verify_case(5, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 5; long long Arg1 = 7LL; int Arg2 = 12; verify_case(6, Arg2, countJourneys(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PenguinEmperor ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
