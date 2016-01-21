#include "../machine_learning.h"

template<typename T>
class matrix {
    private:
        int n;
        T a[MATRIX_SIZE][MATRIX_SIZE];

    public:
        void clear() {forn (i, n) forn (j, n) a[i][j] = 0;}
        matrix(){}
        matrix(int z) { n = z; clear(); }
        matrix operator + (const matrix& u);
        matrix operator * (const matrix& u);
        matrix pow(int k);
        matrix calc(int); // A + A^2 + A^3 + ... + A^k
};
