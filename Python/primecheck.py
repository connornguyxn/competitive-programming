from math import sqrt

def is_prime(n):
    if (n % 2 == 0) or (n < 2):
        return False
    for i in range(3, int(sqrt(n) + 1), 2):
        if n % i == 0:
            return False
    return True

n = int(input())
if is_prime(n):
    print('YES')
else:
    print('NO')