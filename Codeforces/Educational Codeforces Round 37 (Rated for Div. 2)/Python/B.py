from sys import stdout, exit
from operator import itemgetter, attrgetter, methodcaller

maxn = 1000 + 10

interval = []
res = [0 for i in range(maxn)]

if __name__ == '__main__':
    test_cases = int(raw_input())
    for current_test in range(test_cases):
        n = int(raw_input())
        del interval[:]
        for i in range(n):
            u, v = map(int, raw_input().split(' '))
            node = u, v, i
            interval.append(node)
        interval.sort(key = itemgetter(0, 2))
        # print interval
        time = interval[0][0]
        for i in range(n):
            if (interval[i][1] < time):
                res[interval[i][2]] = 0
                if (i < n - 1): time = max(time, interval[i + 1][0])
            else:
                res[interval[i][2]] = time
                if (i < n - 1): time = max(time + 1, interval[i + 1][0])
        for i in range(n):
            print res[i],
        print
