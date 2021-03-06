// BEGIN CUT HERE

// END CUT HERE
#line 5 "RobotHerb.cpp"
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

ll dx[4] = {0, 1, 0, -1}; 
ll dy[4] = {1, 0, -1, 0};
class RobotHerb
{
    public:
        long long getdist(int TT, vector <int> aa)
        {
            vector<ll> a;
            ll T = TT;
            for(int i = 0; i < (int)aa.size(); i++) a.push_back(aa[i]);

            ll n = a.size();
            ll x = 0, y = 0, d = 0;
            for(int i = 0; i < 4 * n; i++)
            {
                int s = i % n;
                x += a[s] * dx[d];
                y += a[s] * dy[d];
                d = (d + a[s]) % 4;
            }
            x *= (T / 4);
            y *= (T / 4);
            for(int i = 0; i < (T % 4) * n; i++)
            {
                int s = i % n;
                x += a[s] * dx[d];
                y += a[s] * dy[d];
                d = (d + a[s]) % 4;
            }
            return (x > 0 ? x : -x) + (y > 0 ? y : -y);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, getdist(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, getdist(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(2, Arg2, getdist(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000000; int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 100000000000LL; verify_case(3, Arg2, getdist(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 570; int Arr1[] = {2013,2,13,314,271,1414,1732}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4112LL; verify_case(4, Arg2, getdist(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RobotHerb ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
