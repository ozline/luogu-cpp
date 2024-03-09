#include <iostream>

using namespace std;

inline int read() {
    int x = 0, w = 1; char ch = 0;
    while(ch < '0' || ch > '9') { if(ch == '-') w = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return(x * w);
}


int cal(int num, int x) {
    int base = 1;
    int sum = 0;
    int n = num;
    while(n != 0) {
        if(x == 0) sum += base * (n / 10 - 1);
        else sum += base * (n / 10);

        int cur = n % 10;
        if(cur == x) sum += num % base + 1;
        else if (cur > x) sum += base;
        base *= 10; n /= 10;
    }
    return sum;
}

void solve(int x) {
    for(int i = 0; i < 10; i++) {
        if(i) cout << " ";
        cout << cal(x, i);
    }
    putchar('\n');
}

int main() {
    int t = read();
    while(t--) {
        solve(read());
    }
}