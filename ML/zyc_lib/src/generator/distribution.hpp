#ifndef _DISTRIBUTION_H_
#define _DISTRIBUTION_H_

#include "../machine_learning.h"

#define ran(x) ran1(x)

typedef enum
{
    Distribution_Type_Gaussian,
    Distribution_Type_Uniform,
}Distribution_Type;

class Distribution
{
    private:
        //All distribution have the default multiple [-1, 1], default bias 0
        double gasdev(int *idum);
        double uniform(int *idum);
    public:
        double get(int bias, int multiple, Distribution_Type type, int *idum)
        {
            double ret = 0;
            if(type == Distribution_Type_Gaussian) ret = gasdev(idum);
            else if(type == Distribution_Type_Uniform) ret = uniform(idum);
            else assert(false);
            return ret * multiple + bias;
        }


};

#endif
