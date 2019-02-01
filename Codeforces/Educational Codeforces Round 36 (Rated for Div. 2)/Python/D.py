from sys import stdout, exit

maxn = 500 + 10
neighbor = [[] for i in range(maxn - 5)]
foundCycle = False
check = [False for i in range(maxn - 5)]
parent = [0 for i in range(maxn - 5)]
tend = 0; start = 0

def dfs(u, cond1, cond2):
    global foundCycle, tend, start
    global parent
    global check
    check[u] = True
    for i in range(len(neighbor[u])):
        if (foundCycle): return
        v = neighbor[u][i]
        if (u == cond1 and v == cond2): continue
        if ((not check[v]) and parent[v] == 0):
            parent[v] = u
            dfs(v, cond1, cond2)
            if (foundCycle): return
        elif (check[v]):
            foundCycle = True
            tend = u
            start = v
        else:
            pass
        if (foundCycle): return
    check[u] = False

n, m = map(int, raw_input().split(' '))
for i in range(m):
    u, v = map(int, raw_input().split(' '))
    neighbor[u].append(v)
foundCycle = False
for i in range(n):
    if parent[i + 1] == 0:
        parent[i + 1] = -1
        dfs(i + 1, 0, 0)
if (not foundCycle):
    print "YES"
    exit()
path = []
while tend != start:
    path.append(tend)
    tend = parent[tend]
path.append(start)
path.append(path[0])
for i in range(len(path) - 1, 0, -1):
    check = [False for j in range(maxn - 5)]
    parent = [0 for j in range(maxn - 5)]
    foundCycle = False
    for j in range(n):
        if parent[j + 1] == 0:
            parent[j + 1] = -1
            dfs(j + 1, path[i], path[i - 1])
    if (not foundCycle):
        print "YES"
        exit()
print "NO"
