q = int(raw_input())
for i in range(q):
    n = int(raw_input())
    s = str(raw_input())
    if n <= 1: print "NO"
    elif n == 2 and s[0] >= s[1]: print "NO"
    else:
        print "YES"
        print 2
        print "{} {}".format(s[0], s[1:])
