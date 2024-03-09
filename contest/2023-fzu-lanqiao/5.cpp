#include <iostream>
#include <ctype.h>


#define MAXN 300000

using namespace std;

int len;
char list[MAXN];
string ans = "";

void solve() {
    cin >> len;
    for(int i = 0; i < len; i++) {
        cin >> list[i];
        while(!isalpha(list[i])) cin >> list[i];
    }

    int left = 0, right = len - 1;
    while(left <= right) {
        if(list[left] < list[right]) {
            ans += list[left];
            left++;
        } else if(list[left] > list[right]) {
            ans += list[right];
            right--;
        } else {
            int l = left, r = right;
            while(l < r && list[l] == list[r]) {
                l++;
                r--;
            }
            if(l >= r) {
                ans += list[left];
                left++;
            } else if(list[l] < list[r]) {
                ans += list[left];
                left++;
            } else {
                ans += list[right];
                right--;
            }
        }
    }
    for(int i = 0; i < len; i++) {
      	if(i % 80 == 0) cout << endl;
        cout << ans[i];
    }
    if(len % 80) cout << endl;
}

int main() {
    solve();
}