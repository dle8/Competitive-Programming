n = int(raw_input())
while n:
    n -= 1
    k, x = map(int, raw_input().split(' '))
    print x + 9 * (k - 1)
