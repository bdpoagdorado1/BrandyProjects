#Brandy Poag-Dorado
def eea(a,b):
    c,c1,r,r1 = 1,0,a,b
    while r1 != 0:
        q = r / r1
        c, c1, r, r1 \
            = c1, c-q*c1, r1, r-q*r1
    return r, c

def inv(a, n):
    gcd,x = eea(n, a)
    if gcd == 1:
        return True, x
    else:
        return None, None
exist, inverse = inv(392071526473, 838733716434923123)
#exist, inverse = inv(52, 3)

print "exist ", exist, "  inverse  ", inverse

#(a) True   inverse   184854506187
#(b) Does not have an inverse
