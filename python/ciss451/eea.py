#Brandy Poag-Dorado

def eea(a,b):
    c,d,c1,d1,r,r1,count = 1,0,0,1,a,b,1
    while r1 != 0:
        q = r / r1
        print count, " ... ", q, ' ', c, ' ', d, ' ', c1, ' ', d1, ' ', r, ' ', r1
        c, d, c1, d1, r, r1 \
            = c1, d1, c-q*c1, d-q*d1, r1, r-q*r1
        count+=1
    print count, " ... ", q, ' ', c, ' ', d, ' ', c1, ' ', d1, ' ', r, ' ', r1
    print "gcd = ", r, '\n', "x = ", c, '\n', "y = ", d
    return r, c, d

eea(100, 30)
"""
#Results:
#print "gcd of a = ", 100, "  b = ", 30

1 ... 1 0 0 1 100 30
2 ... 3 0 1 1 -3 30 10
3 ... 3 1 -3 -3 10 10 0
gcd = 10
x = 1
y = -3

#print "gcd of a = ", 123, "  b ", 57

1 ... 1 0 0 1 123 57
2 ... 2 0 1 1 -2 57 9
3 ... 6 1 -2 -6 13 9 3
4 ... 3 -6 13 19 -41 3 0
gcd = 3
x = -6
y = 13
"""


'''
for a in range(990, 1000):
    for b in range(999, 1000):
        gcd, x, y = eea(a, b)
        if gcd != a*x + b*y:
            print "ERROR! ...", a, b
        else:
            print "gcd ", gcd, "  x ", x, "  y ", y, " a ", a, "  b ", b
            
'''
