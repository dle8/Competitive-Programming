n, k = map(int, raw_input().split(' '))
a = map(int, raw_input().split(' '))
s = str(raw_input())

global u, v
interval = []
for i in range(n):
    if (i == 0 or (s[i] != s[i - 1])): u = i
    if (i == (n - 1) or (s[i] != s[i + 1])):
        v = i
        interval.append((u, v))

res = 0
for (l, r) in interval:
    a[l : (r + 1)] = sorted(a[l : (r + 1)], reverse=True)
    for j in range(min(k, r - l + 1)):
        res += a[l + j]

print res
