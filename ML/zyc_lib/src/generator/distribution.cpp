#include "distribution.hpp"
#include "math.h"
#include "../random/random.hpp"

double Distribution::gasdev(int *idum)
{
    static int iset=0;
    static double gset;
    double fac,rsq,v1,v2;
    if (*idum < 0) iset=0;
    if (iset == 0) {
        do {
            v1=2.0*ran(idum)-1.0;
            v2=2.0*ran(idum)-1.0;
            rsq=v1*v1+v2*v2;
        }while (rsq >= 1.0 || rsq == 0.0);
        fac=sqrt(-2.0*log(rsq)/rsq);
        gset=v1*fac;
        iset=1;
        return v2*fac;
    } else {
        iset=0;
        return gset;
    }
}

double Distribution::uniform(int *idum)
{
   return ran(idum) * 2 - 1; 
}
