x = int(input())

mod = 10**9 + 7

x = int((x + 0.5) ** 0.5)

ans = ((x % mod) * ((x + 1) % mod) * ((2 * x + 1) % mod)) % mod

ans = (ans * pow(6, -1, mod)) % mod

print(ans)