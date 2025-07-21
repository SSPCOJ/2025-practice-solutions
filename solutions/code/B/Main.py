def gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a


p, q = map(int, input().split())
g = gcd(p, q)
print(p // g, q // g)
