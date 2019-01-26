if __name__ == '__main__':
    test_cases = int(raw_input())
    for i in range(test_cases):
        n, k = map(int, raw_input().split())
        tap = map(int, raw_input().split())
        d = 1
        c = n
        while d <= c:
            mid = (d + c) / 2
            prev = 1
            ok = True
            for x in tap:
                if (x - (mid - 1) > prev):
                    ok = False
                    break
                prev = x + (mid - 1) + 1
            if (prev <= n):
                ok = False
            if (ok): c = mid - 1
            else: d = mid + 1
        print d
