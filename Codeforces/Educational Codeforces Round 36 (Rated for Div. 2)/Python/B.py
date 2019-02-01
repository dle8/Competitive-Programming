from sys import stdout, exit
n, pos, l, r = map(int, raw_input().split(' '))
if (l == 1 and r == n):
    print 0
    exit()
sec = 0
if (l == 1):
    sec += abs(pos - r)
    sec += 1
    print sec
    exit()
elif (r == n):
    sec += abs(pos - l)
    sec += 1
    print sec
    exit()
else:
    pass

sec += min(abs(pos - l), abs(pos - r)) + 1 + (r - l) + 1
print sec