// BEGIN CUT HERE

// END CUT HERE
#line 5 "CirclesGame.cpp"
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

bool in[100];
int sg[100], f[100];
int inf = 1e9;
int point[100], pc = 0, has[100];
vector<int> e[100];

void get_point(int u)
{
    point[pc++] = u; 
    for(int i = 0; i < (int)e[u].size(); i++) get_point(e[u][i]);
}
int get_sg(int u)
{
    if(e[u].size() == 0) sg[u] = 1;
    if(sg[u] != -1) return sg[u]; 
    for(int i = 0; i < (int)e[u].size(); i++)
    {
        get_sg(e[u][i]);
    }
    pc = 0;
    get_point(u);
    clr(has, 0);
    for(int i = 0; i < pc; i++)
    {
        int v = point[i], pv = -1, w = 0;
        while(pv != u)
        {
            for(int  j = 0; j < (int)e[v].size(); j++)
            {
                if(e[v][j] != pv) w ^= sg[e[v][j]];
            }
            pv = v;
            v = f[v];
        }
        has[w] = 1;
    }
    sg[u] = 0;
    for(int i = 0; has[i]; i++)
    {
        sg[u]++;
    }
    return sg[u];
}
class CirclesGame
{
    public:
        string whoCanWin(vector <int> x, vector <int> y, vector <int> r)
        {
            int n = x.size();
            for(int i = 0; i < n; i++)
            {
                in[i] = 0;
                sg[i] = -1;
                e[i].clear();
            }
            for(int i = 0; i < n; i++)
            {
                int minimum_radius = inf, p = -1;
                for(int  j = 0; j < n; j++)
                {
                    if(i == j) continue;
                    if(r[i] < r[j] && (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) < r[j] * r[j])  
                    {
                        if(minimum_radius > r[j])
                        {
                            minimum_radius = min(minimum_radius, r[j]);
                            p = j;
                        }
                    }
                }
                if(minimum_radius != inf)
                {
                    in[i] = 1;
                    e[p].push_back(i);
                    f[i] = p;
                }
            }
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(in[i] == 0) 
                {
                    ans ^= get_sg(i);
                }
            }
            if(ans != 0) return "Alice";
            else return "Bob";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(0, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(1, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 0, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(2, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0, 0, 0, 10, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(3, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10,20,30,40,50,60,70,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2,2,2,2,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(4, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0, 3, 6, 9, 12, -4747, -4777}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5858, -5858, -5858, -5858, -5858, 777, 777}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {58, 1, 1, 1, 1, 44, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Bob"; verify_case(5, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Alice"; verify_case(6, Arg3, whoCanWin(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CirclesGame ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
