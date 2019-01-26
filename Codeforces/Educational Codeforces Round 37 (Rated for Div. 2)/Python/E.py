from sys import stdout, exit
from operator import itemgetter, attrgetter, methodcaller
import Queue

maxn = 200000 + 10
noEdge = [set() for i in range(maxn)] # create an array of a empty set
notVisited = set() # create a empty set

def visit(s):
    notVisited.discard(s)
    stack = []
    stack.append(s)
    cnt = 1
    while len(stack) > 0:
        u = stack.pop()
        temp = []
        for v in notVisited:
            if v not in noEdge[u]:
                temp.append(v)
                stack.append(v)
        cnt += len(temp)
        for v in temp: notVisited.discard(v)

    return cnt

n, m = map(int, raw_input().split(' '))
for i in range(m):
    u, v = map(int, raw_input().split(' '))
    noEdge[u].add(v)
    noEdge[v].add(u)

res = []
for i in range(n): notVisited.add(i + 1)
current = 1
while len(notVisited) > 0:
    while (current not in notVisited) and (current <= n):
        current += 1
    if current > n:
        break
    res.append(visit(current))

res.sort()
print len(res)
print ' '.join(map(str, res))
