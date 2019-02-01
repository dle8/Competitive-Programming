from sys import stdout, exit

maxn = 20 + 10
alpha = 1000 + 10
check = [False for i in range(25)]
sla = [0 for i in range(25)]
slb = [0 for i in range(25)]

a = str(raw_input())
b = str(raw_input())
if (len(a) < len(b)):
    print ''.join(sorted(a, reverse=True))
    exit()
else:
    v = []
    for i in range(len(a)):
        sla[long(a[i])] += 1;
        slb[long(b[i])] += 1;
        v.append(a[i])
    equal = True
    for i in range(len(a)):
        if (sla[long(a[i])] != slb[long(a[i])]): equal = False
    if (equal):
        print b
        exit()
    else:
        pass
    res = ""
    for i in range(len(b)):
        minDiff = 1000; tmp = -1
        for j in range(len(a)):
            if ((not check[j]) and (long(b[i]) - long(a[j]) >= 0) and (long(b[i]) - long(a[j]) < minDiff)):
                minDiff = long(b[i]) - long(a[j])
                tmp = j
        if (a[tmp] == b[i] and i != len(b) - 1):
            index = -1
            for j in range(len(v)):
                if (v[j] == a[tmp]): index = j
            del v[index]
            v.sort()
            s1 = ""; s2 = b[(i + 1):]
            for j in range(len(v)):
                s1 += v[j]
            t1 = long(s1); t2 = long(s2)
            if t1 > t2:
                v.append(a[tmp])
                minDiff = 1000
                for j in range(len(a)):
                    if ((not check[j]) and (long(b[i]) - long(a[j]) > 0) and (long(b[i]) - long(a[j]) < minDiff)):
                        minDiff = long(b[i]) - long(a[j])
                        tmp = j
                for j in range(len(v)):
                    if v[j] == a[tmp]: index = j
                del v[index]
        res += a[tmp]
        check[tmp] = True
        if (a[tmp] != b[i]): break
    v = []
    for i in range(len(a)):
        if (not check[i]):
            v.append(a[i])
    v.sort(reverse=True)
    for i in range(len(v)): res += v[i]
    print ''.join(res)