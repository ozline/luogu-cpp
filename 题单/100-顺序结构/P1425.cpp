#include <iostream>
using namespace std;
int main()
{
    int n,b,c,d;
    cin>>n>>b>>c>>d;
    int x=c-n,y=d-b;
    if(y<0){x--;y+=60;}
    cout<<x<<" "<<y;
    return 0;
}