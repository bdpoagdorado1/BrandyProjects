"""
Dr. Liow
"""

class Ring:
    def __init__(self):
        raise NotImplementedError()
    def __str__(self):
        raise NotImplementedError()
    def __eq__(self):
        raise NotImplementedError()
    def __add__(self):
        raise NotImplementedError()
    def __sub__(self):
        raise NotImplementedError()
    def __mul__(self):
        raise NotImplementedError()
    def __pow__(self):
        raise NotImplementedError()
    def __div__(self):
        raise NotImplementedError()
    def inverse(self):
        raise NotImplementedError()

    
class ZN(Ring):

    def __init__(self, v, N):
        if not isinstance(v, int):
            raise ValueError("%s is not an int" % v)
        self.data = v % N
        self.N = N

    def __str__(self):
        #return "%s mod %s" % (self.data, self.N)
        return "%s" % (self.data)

    def assert0(self, z):
        if not isinstance(z, ZN):
            raise ValueError("non-ZN value")
            #print "z is a ", type(z)
        if self.N != z.N:
            raise ValueError("inconsistent mods")

    def __eq__(self, z):
        if isinstance(z, int): z = ZN(z, self.N)
        if not isinstance(z, ZN): return False
        return self.data == z.data and self.N == z.N

    def __neq__(self, z):
        return not(self == z)
    
    def __add__(self, z):
        if isinstance(z, int): z = ZN(z, self.N)
        else: self.assert0(z)
        return ZN((self.data + z.data) % self.N, self.N)

    def __sub__(self, z):
        if isinstance(z, int): z = ZN(z, self.N)
        else: self.assert0(z)
        return ZN((self.data - z.data) % self.N, self.N)

    def __mul__(self, z):
        if isinstance(z, int): z = ZN(z, self.N)
        else: self.assert0(z)
        return ZN((self.data * z.data) % self.N, self.N)

    def __pow__ (self, z):
        if isinstance(z, ZN): z = z.data
        if not isinstance(z, int): raise ValueError("%s is not an int" % z)
        if z == 0:
            if self.data == 0:
                raise ValueError("0**0 error")
            else:
                return ZN(1, self.N)
        elif z > 0:
            return ZN(pow(self.data, z, self.N), self.N)
        else: # z < 0
            inv = self.inverse()
            return ZN(pow(self.data, -z, self.N), self.N)

    def inverse(self):
        inverse = self.eea(self.data, self.N)
        if inverse == 0: return None
        else: return inverse
        """ Computation of inverse by brute force.
        Use Euclidean algorithm instead.
        """
        """
        for i in range(self.N):
            print i, self.data, self.N
            if (self.data * i) % self.N == 1:
                ret = ZN(i, self.N)
                print "inverse of", self, "=", ret
        print "inverse is None ..."
        return None
        """
    def eea(self,a,b):
        c,d,c1,d1,r,r1,count = 1,0,0,1,a,b,1
        while r1 != 0:
            q = r / r1
            #print count, " ... ", q, ' ', c, ' ', d, ' ', c1, ' ', d1, ' ', r, ' ', r1
            c, d, c1, d1, r, r1 \
                = c1, d1, c-q*c1, d-q*d1, r1, r-q*r1
            count+=1
        #print count, " ... ", q, ' ', c, ' ', d, ' ', c1, ' ', d1, ' ', r, ' ', r1
        #print "gcd = ", r, '\n', "x = ", c, '\n', "y = ", d
        #return r, c, d
        #c is the inverse,s r is gcd
        return c

    def __div__(self, z):
        print "in __div__"
        if isinstance(z, int): z = ZN(z, self.N)
        else:
            print "__div__ ... z:", z, type(z), z.__class__
            self.assert0(z)
        return self * z.inverse()

def ZN_range(N):
    return [ZN(i, N) for i in range(N)]

"""
class EC:
    # y**2 = a*x**3 + b*x**2 + c*x + d
    def __init__(self, a, b, c, d, N):
        a.assert0(b)
        a.assert0(c)
        a.assert0(d)
        
        self.a = a
        self.b = b
        self.c = c
        self.d = d

"""

a = ZN(11, 10) # a is 11 mod 10
print "a:", a

b = ZN(12, 10)# b is 12 mod 10
print "b:", b

a += b
print "a:", a
c = a + b
print "c:", c
        
print ZN(2, 5) == ZN(2, 5)
print ZN(2, 5) == ZN(7, 5)
print ZN(2, 5) == ZN(-3, 5)
print ZN(2, 5) == ZN(3, 5)
print ZN(2, 5) != ZN(3, 5)

a = ZN(2,  10)
b = a**10
print b
c= ZN(2, 10)
print a**c

print ZN(4, 5) + 1
print "1/3:", ZN(1,5) / 3

print
print "Z/5 points in E:y**2 = x**3 - 2"
for x in ZN_range(5):
    for y in ZN_range(5):
        if y**2 == x**3 - 2:
            print x, y


print
print "inverses mod 10"
for i in ZN_range(10):
    i_inv = i.inverse()
    if i_inv == None:
        print i, "NO INVERSE"
    else:
        print i, i_inv, i * i_inv

print
print "inverses mod 11"
for i in ZN_range(11):
    i_inv = i.inverse()
    if i_inv == None:
        print i, "NO INVERSE"
    else:
        print i, i_inv, i * i_inv

for x in range(7):
    for y in range(7):
        if (y*y)%7 == (x*x*x-2)%7:
            print x, y
            
print
print "Z/7 points in E:y**2 = x**3 - 2"
for x in ZN_range(7):
    for y in ZN_range(7):
        if y**2 == x**3 - 2:
            print x, y
"""
print
print "Z/7 points in E:y**2 = x**3 + a*x**2 + b*x + c"
N = 7
a = ZN(0, N)
b = ZN(0, N)
c = ZN(-2, N)
for x in ZN_range(N):
    for y in ZN_range(N):
        if y**2 == x**3 + a*x**2 + b*x + c:
            print x,
            """



