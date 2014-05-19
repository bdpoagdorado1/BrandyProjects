LconNums = []
decNumbers = []
decMess = []

##############################################################################
message = "GRlwDZSBqvwDeTxOSRzZSWRRwQfeTx"
alphabet = [] #these are the inverses
alphabet.append("a")
alphabet.append("b")
alphabet.append("c")
alphabet.append("d")
alphabet.append("e")
alphabet.append("f")
alphabet.append("g")
alphabet.append("h")
alphabet.append("i")
alphabet.append("j")
alphabet.append("k")
alphabet.append("l")
alphabet.append("m")
alphabet.append("n")
alphabet.append("o")
alphabet.append("p")
alphabet.append("q")
alphabet.append("r")
alphabet.append("s")
alphabet.append("t")
alphabet.append("u")
alphabet.append("v")
alphabet.append("w")
alphabet.append("x")
alphabet.append("y")
alphabet.append("z")

alphabet.append("A")
alphabet.append("B")
alphabet.append("C")
alphabet.append("D")
alphabet.append("E")
alphabet.append("F")
alphabet.append("G")
alphabet.append("H")
alphabet.append("I")
alphabet.append("J")
alphabet.append("K")
alphabet.append("L")
alphabet.append("M")
alphabet.append("N")
alphabet.append("O")
alphabet.append("P")
alphabet.append("Q")
alphabet.append("R")
alphabet.append("S")
alphabet.append("T")
alphabet.append("U")
alphabet.append("V")
alphabet.append("W")
alphabet.append("X")
alphabet.append("Y")
alphabet.append("Z")
###############################################################################
nums = [] #these are the inverses
nums.append(1)
nums.append(35)
nums.append(21)
nums.append(15)
nums.append(29)
nums.append(19)
nums.append(7)
nums.append(49)
nums.append(11)
nums.append(5)
nums.append(43)
nums.append(25)
nums.append(27)
nums.append(9)
nums.append(47)
nums.append(41)
nums.append(3)
nums.append(45)
nums.append(33)
nums.append(23)
nums.append(37)
nums.append(31)
nums.append(17)
nums.append(51)
##############################################################################
def conToNum(m):
    for i in range(len(m)):
        if(ord(m[i]) < 97):
            LconNums.append(ord(m[i])-ord("A")+26)
        else:
            LconNums.append(ord(m[i])-ord("a"))
##############################################################################
def decrypt(numbers):
    for i in range(len(nums)):
        for j in range(52):
            tempDecNumbers = []
            for k in range(len(numbers)):
                current_integer = (nums[i]*numbers[k] + j)%52
                tempDecNumbers.append(current_integer)
            getDec = conToLet(tempDecNumbers)
            print getDec
            print "i = ", i
            print "j = ", j
            print ""
            decNumbers.append(getDec)
##############################################################################
def conToLet(n):
    myarray = []
    for i in range(len(n)):
        test = n[i]
        if(n[i] < 26):
            myarray.append(chr(n[i]+97))
        else:
            myarray.append(alphabet[test])
    return(myarray)
##############################################################################
conToNum(message)
decrypt(LconNums)
#conToLet(decNumbers)
#print LconNums

#for i in range(len(decNumbers)):
#    print decNumbers[i]


#message = raw_input("Enter encoded message")


