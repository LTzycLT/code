#include "data.hpp"
#include "machine_learning.h"

int PLA(Input<double, bool> input, Thetas<double> t)
{
    int n = input.get_n();
    int m = input.get_m();

    for(int i = 0; i < m; i++)
    {
        input.get_case(i).log();
    }

    t.clear();
    for(int i = 0; i < n; i++) t.add(0);
    t.set(0, 1);

    while(true)
    {
        t.log();
        int i;
        for(i = 0; i < m; i++)
        {
            double sum = 0;
            Case<double, bool> cs = input.get_case(i);
            for(int j = 0; j < n; j++)
            {
                sum += cs.get_x(j) * t.get(j); 
            }
            if(sum * cs.get_y() <= 0)
            {
                for(int j = 0; j < n; j++)
                {
                    t.set(j, t.get(j) + cs.get_y() * cs.get_x(j));
                    break;
                }
            }
        }
        if(i == m)
        {
            break;
        }
    }
    t.log();
    return YES;
}
