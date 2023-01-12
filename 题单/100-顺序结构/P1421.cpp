#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,b;
    float c;
    cin>>a>>b;
    c=a+float(b)/10;
    cout<<floor(c/1.9);
    return 0;
}