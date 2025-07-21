import sys
from math import ceil

input = lambda: sys.stdin.readline().rstrip()


class Polynomial:
    def __init__(self, coeff: list[int]):
        self.coeff = coeff

    def __call__(self, x: int) -> int:
        ret = 0
        x_power = 1
        for i in range(len(self.coeff)):
            ret += x_power * self.coeff[i]
            x_power *= x
        return ret


LIMIT = int(1e8)

T = int(input())
for _ in range(T):
    d = int(input())
    f = Polynomial(list(map(int, input().split())))

    lo = 1
    hi = ceil(ceil(LIMIT / f.coeff[-1]) ** (1 / d)) + 1
    while lo < hi:
        mid = (lo + hi) // 2
        if f(mid) <= LIMIT:
            lo = mid + 1
        else:
            hi = mid
    print(lo - 1)
