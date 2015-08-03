/*
 * Make sure all bitset has same length in same case.
 * It will not be set to zero when construction.
 */
const int BN = 20000;
const long long mask = -1;
class bitset {
    int n, m;
    long long b[BN / 64 + 1];

    public:
    bitset(int __n) {
        n = __n;
        m = n / 64;
        if(n % 64 != 0) m++;
    }

    inline void set(int l, int x){
        if(x) b[l >> 6] |= (1LL << (l & 63));
        else b[l >> 6] &= ~(1LL << (l & 63));
    }
    inline bool get(int l) const{
        return (b[l >> 6] >> (l & 63)) & 1;
    }
    void set(int l, int r, bool x){
        int i;
        long long w = x ? mask : 0;
        for(i = l; (i & 63) && i < r; i++) set(i, x);
        for(; i < r; i += 64) b[i >> 6] = w;
        for(; i < r; i++) set(i, x);
    }

    int count(long long x) {
        long long y = x;  
        y >>= 1;
        while(y){x-= y; y >>= 1;}
        return x;
    }
    bool zero_interval(int l, int r) const {
        int i;
        for(i = l; (i & 63) && i < r; i++) if(get(i)) return false;
        for(; i < r; i += 64) if(b[i >> 6]) return false;
        for(; i < r; i++) if(get(i)) return false;
        return true;
    }

    void get_mask(int n, long long &l_mask, long long &r_mask) const {
        if(n == 64) l_mask = mask; 
        else if(n == 0) l_mask = 0;
        else l_mask = (1LL << n) - 1; 
        r_mask = mask - l_mask;
    }
    // x >= 0
    bitset operator << (int x) const {
        bitset ret(n);
        int s = x >> 6, t = x & 63, tt = 64 - t;
        long long suf, pre;
        get_mask(tt, pre, suf);
        for(int i = m - s - 1, j = m - 1, k = m; i >= 0; i--, j--, k--){
            ret.b[j] = (b[i] & pre) << t;
            if(k < m) ret.b[k] |= (b[i] & suf) >> tt;
        }
        ret.set(0, x, 0);
        return ret;
    }
    // x >= 0
    bitset operator >> (int x) const {
        bitset ret(n); 
        int s = x >> 6, t = x & 63, tt = 64 - t;
        long long pre, suf;
        get_mask(t, pre, suf);
        for(int i = s, j = 0, k = -1; i < m; i++, j++, k++){
            ret.b[j] = (b[i] & suf) >> t;
            if(k >= 0) ret.b[k] |= (b[i] & pre) << tt;
        }
        ret.set(n - x, n, 0);
        return ret;
    }

    bitset operator & (const bitset &u) const {
        bitset ret(n); 
        for(int i = 0; i < m; i++) ret.b[i] = b[i] & u.b[i];  
        return ret;
    }

    bitset operator | (const bitset &u) const {
        bitset ret(n); 
        for(int i = 0; i < m; i++) ret.b[i] = b[i] | u.b[i];  
        return ret;
    }
    void print() const{
        for(int i = 0; i < n; i++){
            if((i & 63) == 0) printf(" ");
            if(get(i))  printf("1");
            else printf("0");
        }
        puts("");
    }
};

