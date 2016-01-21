// BEGIN CUT HERE

// END CUT HERE
#line 5 "SubdividedSlimes.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<set>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

multiset<int> st;
const int N = 105;
ll dp[N][N];

class SubdividedSlimes
{
    int solve1(int S, int M)
    {
        st.clear();
        st.insert(S);
        ll ans = 0, k = 0;
        while(st.size() > 0)
        {
            multiset<int>::iterator it = st.end();
            it--;
            int tmp = *it;
            st.erase(it);
            k += 1; 
            int a = tmp / 2, b = (tmp - tmp / 2);
            ans += a * b;
            if(a > 1) st.insert(a);
            if(b > 1) st.insert(b);
            if(ans >= M) 
            {
                return k;
            }
        }
        return -1;
    }
    int solve2(int S, int M)
    {
        clr(dp, 0);
        for(int i = 2; i <= S; i++) 
        {
            for(int j = 1; j <= i; j++)
            {
                for(int k = 1; k < i; k++) 
                {
                    for(int l = 0; l < j; l++)
                    {
                        dp[i][j] = max(dp[i][j], dp[k][l] + dp[i - k][j - l - 1] + (i - k) * k);
                    }
                }
            }
        }
        for(int i = 0; i <= S; i++)
        {
            if(dp[S][i] >= M)
                return i;
        }
        return -1;
    }
    int solve3(int S, int M)
    {
        for(int i = 2; i <= S; i++)
        {
            int k = S / i;
            int a = S % i;
            int b = i - a;
            if(k * k * b * (b - 1) / 2 + (k + 1) * (k + 1) * a * (a - 1) / 2 + k * (k + 1) * a * b >= M)
            {
                return i - 1;
            }
        }
        return -1;
    }
    public:
        int needCut(int S, int M)
        {
            return solve3(S, M);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; verify_case(0, Arg2, needCut(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, needCut(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = -1; verify_case(2, Arg2, needCut(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 765; int Arg1 = 271828; int Arg2 = 14; verify_case(3, Arg2, needCut(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SubdividedSlimes ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
