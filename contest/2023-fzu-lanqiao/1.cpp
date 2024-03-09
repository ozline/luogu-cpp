#include <iostream>
#include <cmath>

#define PI acos(-1)

using namespace std;

inline int read() {
    int x = 0, w = 1; char ch = 0;
    while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return(x * w);
}

double square_area = 1.0;
double circle_area = PI / 4.0;


void solve(int p, int index) {
    if(p == 0) {
        printf("Case %d: 0\n", index);
        return;
    }

    double base = 0;
    int ans = 0;
    // while(base < square_area * p * 0.01){
    //     base += circle_area;
    //     ans++;
    // }
    ans = ceil(sqrt(2) * p * 0.01);
    printf("Case %d: %d\n", index, ans);
}

int main() {
    freopen("in.in","r",stdin); freopen("out.out","w",stdout);

    int t;
    int index = 0;
    while(cin >> t) {
        solve(t, ++index);
    }

    fclose(stdin); fclose(stdout);
}