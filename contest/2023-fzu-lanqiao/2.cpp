#include <iostream>
#include <cmath>

#define ll unsigned long long

using namespace std;

ll ans, x;
ll mod = 1e9 + 7;

ll quick_pow(ll a, ll b, ll p)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}


int main() {
    cin >> x;
    x = floor(sqrt(x + 0.5));
    ans = (((x % mod) * ((x + 1) % mod) % mod) * ((x * 2 + 1) % mod)) % mod;
    ans = ((ans % mod) * (quick_pow(6, mod - 2, mod) % mod)) % mod;

    printf("%lld", ans);
}

// 乘法逆元
// b^(-1) = b^(mod - 2) % mod