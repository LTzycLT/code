#include "matrix.hpp"

template<typename T>
matrix<T> matrix<T>::operator + (const matrix<T>& u) {
    matrix<T> ans; ans.n = n;
    forn (i, n) forn (j, n) {
        ans.a[i][j] = a[i][j] + u.a[i][j];
        if (ans.a[i][j] >= MOD) ans.a[i][j] %= MOD;
    } return ans;
}

template<typename T>
matrix<T> matrix<T>::operator * (const matrix& u) {
    matrix ans(n);
    forn (i, n) forn (k, n) if (a[i][k])
        forn (j, n) if (u.a[k][j]) {
            ans.a[i][j] += a[i][k] * u.a[k][j];
            if (ans.a[i][j] >= MOD) ans.a[i][j] %= MOD;
        }
    return ans;
}
template<typename T>
matrix<T> matrix<T>::pow(int k) {
    matrix r(n), t = *this;
    forn (i, n) r.a[i][i] = 1;
    while (k) {
        if (k & 1) r = t * r;
        t = t * t;
        k >>= 1;
    } return r;
}
template<typename T>
matrix<T> matrix<T>::calc(int k) {
    matrix r(2 * n), t, ret(n);
    forn(i, n) forn(j, n)
        r.a[i][j] = r.a[i][j + n] = a[i][j];
    forn(i, n) r.a[i + n][i + n] = 1;
    t = r.pow(k);
    forn(i, n) forn(j, n)
        ret.a[i][j] = t.a[i][j + n];
    return ret;
}
