const int N = 100000;
int mob[N];
void init_mobius(int n)
{
    clr(mob, 0);
    for(int i = 1; i <= n; i++)
    {
        if(i == 1) mob[i] = 1;
        else mob[i] *= -1;
        for(int j = i + i; j <= n; j += i)
            mob[j] += mob[i];
    }
}
