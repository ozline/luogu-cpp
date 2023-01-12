#include <iostream>
#include <cmath>

#define PI acos(-1)

using namespace std;


int main()
{
    double t;
    int n;
    cin >> t >> n;
    printf("%.3lf\n%d", t / n, n * 2); 

    return 0;
}