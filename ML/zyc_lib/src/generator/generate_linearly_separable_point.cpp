#include "../data.hpp"
#include "../machine_learning.h"
#include "../random/random.hpp"
#include "distribution.hpp"
#include <vector>
using namespace std;

/*
 * t.size() == n
 * t[0] * x[0] + t[1] * x[1] + ... + t[n - 2] * x[n - 2] + t[n - 1] = 0 
 * x[n - 1] = 1
 */
Case<double, bool> generate_linearly_separable_points(Thetas<double> t)
{
    assert(t.size() >= 2);

    class Distribution d;
    vector<double> x;
    double sum = 0;
    for(int i = 0; i < t.size() - 2; i++)
    {
        double w = d.get(0, NUMERICAL_RANGE, Distribution_Type_Uniform, &idum);
        x.push_back(w);
        sum += w * t.get(i);
    }
    double w = -(sum + t.get(-1)) / t.get(-2);
    double fai = d.get(0, NUMERICAL_RANGE, Distribution_Type_Gaussian, &idum);
    w += fai;
    x.push_back(w);
    x.push_back(1);

    Case<double, bool> cs(x, fai >= 0 ? -1 : 1);
    return cs;
}
