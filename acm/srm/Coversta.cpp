#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#define INC(x,y) {x = (x+y);if(x>=mod) x-=mod;}
#define Min(x,y) {if(y<x) x=y;}
#define Max(x,y) {if(y>x) x=y;}
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;

int n, m, k;
vector<string> a;
vector<int> x;
vector<int> y;
int w[105][105];
multiset<int> number;

class Coversta
{

    int getval(int r, int c)
    {
        if(r < 0 || r >=n || c < 0 || c >= m) 
        {
            return 0;
        }
        else
        {
            return a[r][c] - '0' + 0;
        }
    }
    int cal(int r, int c)
    {
        int sum = 0;
        for(int i = 0; i < k; i++)
        {
            sum += getval(r + x[i], c + y[i]); 
        }
        return sum;
    }
    vector<pair<int, int> > get_duplicate_point(int r, int c)
    {
        vector<pair<int, int> > point;
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                int dx = x[i] - x[j];
                int dy = y[i] - y[j];
                int tx = r + dx;
                int ty = c + dy;
                if(tx >= 0 && tx < n && ty >= 0 && ty < m)
                {
                    bool exist = false;
                    for(int i1 = 0; i1 < (int)point.size(); i1++)
                    {
                        if(point[i1].first == tx && point[i1].second == ty)
                        {
                            exist = true;
                            break;
                        }
                    }
                    if(!exist)
                    {
                        point.push_back(make_pair(tx, ty)); 
                    }
                }
            }
        }
        return point;
    }
    int duplicate_val(int r1, int c1, int r2, int c2)
    {
        int val = w[r1][c1] + w[r2][c2];
        for(int i = 0; i < k; i++)
        {
            int tx = r1 + x[i];
            int ty = c1 + y[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < m)
            {
                bool exist = false;
                for(int j = 0; j < k; j++) 
                {
                    int sx = r2 + x[j];
                    int sy = c2 + y[j];
                    if(tx == sx && ty == sy)
                    {
                        exist = true;
                        break;
                    }
                }
                if(exist)
                {
                    val -= (a[tx][ty] - '0' + 0);
                }
            }
        }
        return val;
    }

public:
	int place(vector <string> aa, vector <int> xx, vector <int> yy){
        number.clear();
        a = aa;
        x = xx;
        y = yy;
        n = a.size();
        m = a[0].size();
        k = x.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                w[i][j] = cal(i, j); 
                number.insert(w[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                vector<pair<int, int> > point = get_duplicate_point(i, j);
                for(int i1 = 0; i1 < (int)point.size(); i1++)
                {
                    int tx = point[i1].first;
                    int ty = point[i1].second;
                    number.erase(number.find(w[tx][ty]));
                    ans = max(ans, duplicate_val(i, j, tx, ty));
                }
                if(number.size() > 0) 
                {
                    multiset<int>::iterator it = number.end();
                    it--;
                    ans = max(ans, w[i][j] + *it);
                }
                for(int i1 = 0; i1 < (int)point.size(); i1++)
                {
                    int tx = point[i1].first;
                    int ty = point[i1].second;
                    number.insert(w[tx][ty]);
                }
            }
        }

		return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"99",
 "99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,-1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 36; verify_case(0, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"11",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"15",
 "61"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 11; verify_case(2, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"151",
 "655",
 "661"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 33; verify_case(3, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"303",
 "333",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(4, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0000000",
 "1010101"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(5, Arg3, place(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	Coversta ___test;
	___test.run_test(0);
	return 0;
}
// END CUT HERE
