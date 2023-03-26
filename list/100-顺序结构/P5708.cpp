#include <iostream>
#include <cmath>

#define PI acos(-1)

using namespace std;


int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    
    double p = 0.5 * (a + b + c);

    printf("%.1lf\n", sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}