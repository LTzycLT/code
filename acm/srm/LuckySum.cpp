// BEGIN CUT HERE

// END CUT HERE
#line 5 "LuckySum.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

string s;
int a[20], n;

bool dfs(int dep, bool x, bool f)
{
    if(dep < 0)
    {
        if(x == 0 && f != 0)
            return true;
        else
            return false;
    }
    if(x == 0)
    {
        if((s[dep] == '?' || s[dep] == '1') && dep == n - 1)
        {
            a[dep] = 1;
            if(dfs(dep - 1, 1, 1)) return true; 
        }
        if((s[dep] == '?' || s[dep] == '4') && f == 0) 
        {
            a[dep] = 4;
            if(dfs(dep - 1, 0, 0)) return true; 
        }
        if((s[dep] == '?' || s[dep] == '5') && f == 0)
        {
            a[dep] = 5;
            if(dfs(dep - 1, 1, 0)) return true; 
        }
        if((s[dep] == '?' || s[dep] == '7') && f == 0)
        {
            a[dep] = 7;
            if(dfs(dep - 1, 0, 0)) return true; 
        }
        if((s[dep] == '?' || s[dep] == '8'))
        {
            a[dep] = 8;
            if(f == 0)
            {
                if(dfs(dep - 1, 1, 0)) return true; 
            }
            if(dfs(dep - 1, 0, 1)) return true; 
        }
        if((s[dep] == '?' || s[dep] == '9'))
        {
            a[dep] = 9;
            if(dfs(dep - 1, 1, 1)) return true;
        }
    }
    else
    {
        if((s[dep] == '?' || s[dep] == '1'))
        {
            a[dep] = 1;
            if(dfs(dep - 1, 0, 1)) return true;
        }
        if((s[dep] == '?' || s[dep] == '2'))
        {
            a[dep] = 2;
            if(dfs(dep - 1, 1, 1)) return true;
        }
        if((s[dep] == '?' || s[dep] == '4'))
        {
            a[dep] = 4;
            if(dfs(dep - 1, 0, 1)) return true;
        }
        if((s[dep] == '?' || s[dep] == '5'))
        {
            a[dep] = 5;
            if(dfs(dep - 1, 1, 1)) return true;
        }
    }
    return false;
}

class LuckySum
{
    public:
        long long construct(string note)
        {
            s = note;
            n = s.size();
            for(int i = 0; i < (int) n / 2; i++)
            {
                swap(s[i], s[n - i - 1]);
            }
            if(!dfs(n - 1, 0, 0)) return -1;
            else
            {
                long long ans = 0;
                for(int i = n - 1; i >= 0; i--)
                {
                    ans = ans * 10 + a[i];
                }
                return ans;
            }
        }

        // BEGIN CUT HERE
    public:
        void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
    private:
        template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
        void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
        void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
        void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
        void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
        void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
        void test_case_4() { string Arg0 = "??????????????"; long long Arg1 = 11888888888888LL; verify_case(4, Arg1, construct(Arg0)); }

        // END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LuckySum ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
