inf = 1e9
n, k = map(int, raw_input().split(' '))
res = inf
a = map(int, raw_input().split(' '))
for i in range(n):
    if k % a[i] == 0: res = min(res, k / a[i])
print res