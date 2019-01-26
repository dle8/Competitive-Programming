from sys import stdout, exit
from operator import itemgetter, attrgetter, methodcaller

maxn = 200000 + 10
interval = []

n = int(raw_input())
a = map(int, raw_input().split(' '))
place = str(raw_input())
place += '0'

global u
for i in range(len(place)):
    if (place[i] == '1' and (i == 0 or place[i - 1] == '0')):
        u = i
    elif (place[i] == '0' and place[i - 1] == '1'):
        node = u, i
        interval.append(node)
    else:
        pass

for (l, r) in interval:
    a[l : (r + 1)] = sorted(a[l : (r + 1)])

for i in range(n):
    if (a[i] != (i + 1)):
        print "NO"
        exit()

print "YES"
