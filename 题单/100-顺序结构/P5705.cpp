#include <iostream>
#include <cmath>

#define PI acos(-1)

using namespace std;


int main()
{
    char a, b, c, d;
    scanf("%c%c%c.%c", &a, &b, &c, &d);
    printf("%c.%c%c%c", d, c, b, a);

    return 0;
}