# Name: Brandy Poag
from ZN import *



def add(e, N, p, q):
    #print " e ", e
    
    a = e[0]
    b = e[1]
    c = e[2]
    #print "adding ", a, " ", b, " ", c
    x1= p[0]
    x2= q[0]
    y1= p[1]
    y2= q[1]
    #print "x1 ", x1, " y1 ", y1, " x2 ", x2, " y2 ", y2
    p_finite = p[2].data
    q_finite = q[2].data
    #print "p fin ", p_finite, "  q fin ", q_finite

    
    #check for infinite points
    if p_finite == 0:
        if q_finite == 0:
            return [ZN(0, N), ZN(1, N), ZN(0, N)]
        else:
            if (y2**2).data == (x2**3 + a*(x2**2) + b*x2 + c).data:
                return q
            else: return None
    elif q_finite == 0:
        if (y1**2).data == (x1**3 + a*(x1**2) + b*x1 + c).data:
            return p
        else: return None
        
    #make sure finite points are on the curve
    if not (y1**2 == x1**3 + a*(x1**2) + b*x1 + c) or \
       not (y2**2 == x2**3 + a*(x2**2) + b*x2 + c):
        print "print point not on curve"
        return None
    
    #handle finite points
    
    
    if not (x1 == x2):
        m = (y2 - y1) / (x2 - x1)
        #print "m  ", m
        c = y1 - (m * x1)
        #print "c  ", c
        x_3 = m**2 - x2 - x1 - a 
        #print "x_3  ", x_3
        y_3 = m * x_3 + c
        #print "y_3  ", y_3
        return [ZN(x_3.data, N), ZN(-(y_3.data), N), ZN(1, N)]
    elif not(y1 == y2):
        return [ZN(0, N), ZN(1, N), ZN(0, N)]
    elif not(y1 == 0):
        m = (ZN(3, N) * x1**2 + ZN(2, N) * a*x1 + b)/(ZN(2, N) * y1)
        #print "m  ", m
        c = y1 - (m * x1)
        #print "c  ", c
        x_3 = m**2 - ZN(2, N)*x1 - a 
        #print "x_3  ", x_3
        y_3 = m * x_3 + c
        #print "y_3  ", y_3
        return [ZN(x_3.data, N), ZN(-(y_3.data), N), ZN(1, N)]
    elif y1 == 0:
        return [ZN(0, N), ZN(1, N), ZN(0, N)]
    else:
        print "error with coordinates"
        return None

N = 7
E = [ZN(0, N), ZN(0, N), ZN(-2, N)]
#P = [ZN(1, N), ZN(0, N), ZN(1, N)]
Q = [ZN(3, N), ZN(5, N), ZN(1, N)]
#Q = [ZN(6, N), ZN(5, N), ZN(1, N)]
P = [ZN(3, N), ZN(2, N), ZN(1, N)]
O = [ZN(0, N), ZN(1, N), ZN(0, N)]

print "P:", P
print "O:", O


print "p: (", P[0].data,", ", P[1].data, ")"
print "q: (", Q[0].data,", ", Q[1].data, ")"
print "O: (", O[0].data,", ", O[1].data, ")"

print "P_add_P:"
P_add_P = add(E, N, P, P)
if P_add_P != None: print "[", P_add_P[0].data, " , ", P_add_P[1].data, " , ", P_add_P[2].data, "]"
else: print "no point returned"

print

print "Q_add_Q:"
Q_add_Q = add(E, N, Q, Q)
if Q_add_Q != None: print "[", Q_add_Q[0].data, " , ", Q_add_Q[1].data, " , ", Q_add_Q[2].data, "]"
else: print "no point returned"


print

print "P_add_Q:"
P_add_Q = add(E, N, P, Q)
if P_add_Q != None: print "[", P_add_Q[0].data, " , ", P_add_Q[1].data, " , ", P_add_Q[2].data, "]"
else: print "no point returned"


print

print "Q_add_P:"
Q_add_P = add(E, N, Q, P)
if Q_add_P != None: print "[", Q_add_P[0].data, " , ", Q_add_P[1].data, " , ", Q_add_P[2].data, "]"
else: print "no point returned"

print

print "P_add_O:"
P_add_O = add(E, N, P, O)
if P_add_O != None: print "[", P_add_O[0].data, " , ", P_add_O[1].data, " , ", P_add_O[2].data, "]"
else: print "no point returned"

print

print "O_add_P:"
O_add_P = add(E, N, O, P)
if O_add_P != None: print "[", O_add_P[0].data, " , ", O_add_P[1].data, " , ", O_add_P[2].data, "]"
else: print "no point returned"

print

print "O_add_O:"
O_add_O = add(E, N, O, O)
if O_add_O != None: print "[", O_add_O[0].data, " , ", O_add_O[1].data, " , ", O_add_O[2].data, "]"
else: print "no point returned"

print

print "Q_add_O:"
Q_add_O = add(E, N, Q, O)
if Q_add_O != None: print "[", Q_add_O[0].data, " , ", Q_add_O[1].data, " , ", Q_add_O[2].data, "]"
else: print "no point returned"

print

print "O_add_Q:"
O_add_Q = add(E, N, O, Q)
if O_add_Q != None: print "[", O_add_Q[0].data, " , ", O_add_Q[1].data, " , ", O_add_Q[2].data, "]"
else: print "no point returned"

