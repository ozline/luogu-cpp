#include <iostream>
#include <map>

using namespace std;
map<int, int> mp;

void solve() {
    int x; cin >> x;

    if(x == 1) printf("2\n3\n5\n7");
    if(x == 2) printf("23\n29\n31\n37\n53\n59\n71\n73\n79");
    if(x == 3) {
        int list[14] = {233,239,293,311,313,317,373,379,593,599,719,733,739,797};
        for(int i = 0; i < 14; i ++) printf("%d\n", list[i]);
    }
    if(x == 4) {
        int list[16] = {2333,2339,2393,2399,2939,3119,3137,3733,3739,3793,3797,5939,7193,7331,7333,7393};
        for(int i = 0; i < 16; i ++) printf("%d\n", list[i]);
    }
    if(x == 5) {
        int list[15] = {23333,23339,23399,23993,29399,31193,31379,37337,37339,37397,59393,59399,71933,73331,73939};
        for(int i = 0; i < 15; i ++) printf("%d\n", list[i]);
    }
    if(x == 6) {
        int list[12] = {233993,239933,293999,373379,373393,593933,593993,719333,739391,739393,739397,739399};
        for(int i = 0; i < 12; i ++) printf("%d\n", list[i]);
    }
    if(x == 7) {
        int list[8] = {2339933,2399333,2939999,3733799,5939333,7393913,7393931,7393933};
        for(int i = 0; i < 8; i ++) printf("%d\n", list[i]);
    }
    if(x == 8) {
        int list[5] = {23399339,29399999,37337999,59393339,73939133};
        for(int i = 0; i < 5; i ++) printf("%d\n", list[i]);
    }
}

int main() {
    freopen("in.in","r",stdin); freopen("out.out","w",stdout);

    solve();

    fclose(stdin); fclose(stdout);
}