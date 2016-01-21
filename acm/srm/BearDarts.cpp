// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearDarts.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<set>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

map<pair<int, int>, int> zyc;

class BearDarts
{
    public:
        long long count(vector <int> w)
        {
            zyc.clear();
            ll ans = 0;
            int n = w.size();
            for(int i = n - 1; i >= 0; i--)
            {
                for(int j = 0; j < i; j++)                
                {
                    int u = w[j], v = w[i];
                    int g = gcd(u, v);
                    u /= g;
                    v /= g;
                    ans += zyc[MP(u, v)];
                }

                for(int j = i + 1; j < n; j++)
                {
                    int u = w[j], v = w[i];
                    int g = gcd(u, v);
                    u /= g;
                    v /= g;
                    zyc[MP(u, v)] += 1;
                }
                
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,4,3,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {3,4,12,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {42,1000000,1000000,42,1000000,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 22LL; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { int Arr0[] = {33554432, 33554432, 67108864, 134217728}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(5, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BearDarts ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
