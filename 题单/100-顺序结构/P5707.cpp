#include <iostream>
#include <cmath>

#define PI acos(-1)

using namespace std;


int main()
{
    int s, v;
    cin >> s >> v;
    int minute = (int)ceil((s * 1.0) / v) + 10;
    int hour =  7 - minute / 60;
    int min = 60 - minute % 60;

    while(hour < 0) hour += 24;
    if(min < 0 ) hour--, min+=60;

    if(hour < 10) cout << "0";
    cout << hour << ":";
    if(min < 10) cout << "0";
    cout << min << endl;

    return 0;
}