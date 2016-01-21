#include "../src/generator/generator.hpp"
#include "../src/classification.hpp"
#include "../src/generator/distribution.hpp"

int main()
{
    class Thetas<double> t;
    class Input<double, bool> input(3);
    t.add(1);
    t.add(-1);
    t.add(0);
    for(int i = 0; i < 10; i++)
    {
        Case<double, bool> cs = generate_linearly_separable_points(t);
        input.add_case(cs);
    }
    PLA(input, t);
    for(int i = 0; i < 3; i++)
    {
        printf("%lf ", t.get(i)); 
    }
}

