#include <iostream>
#include <cmath>

#define PI acos(-1)

using namespace std;


int main()
{
    int h, r;
    cin >> h >> r;
    double v = PI * r * r * h;
    int ans = ceil( (20.0 * 1000)  / v);
    cout << ans << endl;
    return 0;
}