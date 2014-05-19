import string, math, copy, time, datetime

class Huffman:
    def __init__(self, info, filename): #Huffman(info[message, frequencies, symbols], filename)
        print "encoding huffman..."
        result = self.encode(info, filename)
        codeword_book = result[1]
        encoded_message = result[0]
        
        """
        print "decoding..."
        decoded_message = self.decode(encoded_message, codeword_book)
        if decoded_message != info[0]:
            print "Error with Huffman algorithms!"
        else:
            print "Algorithms successful!" """
        #print "h done"

        
    def encode(self, info, filename):
        start = datetime.datetime.now()
        #encode a message with codes from the codeword book
        outcomes = []
        for i in range(len(info[2])):
            outcomes.append([info[1][i], info[2][i]])
        #print outcomes
        codeword_book = self.create_huffman_book_and_tree(outcomes)
        
        encoded_message = ""
        for symbol in info[0]:
            encoded_message += codeword_book[symbol]

        end = datetime.datetime.now()
        t = end - start
        print t
        file_ = open(filename, 'w')
        file_.write(self.analysis(codeword_book, outcomes, len(info[0]), t, len(encoded_message)))
        file_.close()
        return [encoded_message, codeword_book]
    
    def create_huffman_book_and_tree(self, outcomes):
        #create a huffman tree and then create a codeword book from the tree
        seq_of_outcomes = copy.copy(outcomes)
        count = 0
        alpha = ""
        huffman_tree = []
        """create Huffman tree as a list by continually:
                        1.removing
                        2.combining
                        3.appending
        the two lowest frequencies"""
        
        while len(seq_of_outcomes) > 1:
            alpha = ("alpha%i" % count)
            a = min(seq_of_outcomes)
            seq_of_outcomes.remove(a)
            b = min(seq_of_outcomes)
            seq_of_outcomes.remove(b)
            huffman_tree.append([[a[0]+b[0], alpha], b, a])
            count += 1 
            seq_of_outcomes.append([a[0]+b[0], alpha])
            
        codeword_book = {}
        #print huffman_tree
        self.create_codeword_book_from_huffman_tree(alpha, "", huffman_tree, codeword_book)

        return codeword_book
    
    def create_codeword_book_from_huffman_tree(self, alpha, string, huffman_tree, codeword_book):
        #from the root of the huffman tree create codes by appending 0 or 1 for each branch
        for i in range(len(huffman_tree)):
            if huffman_tree[i][0][1] == alpha:
                if "alpha" in huffman_tree[i][1][1]:
                    self.create_codeword_book_from_huffman_tree(huffman_tree[i][1][1], (string+"1"), huffman_tree, codeword_book)
                    
                else:
                    codeword_book[huffman_tree[i][1][1]] = string+"1"
                
            
                if "alpha" in huffman_tree[i][2][1]:
                    self.create_codeword_book_from_huffman_tree(huffman_tree[i][2][1], (string+"0"), huffman_tree, codeword_book)
                    #print "here2..", huffman_tree[i][2][1], (string+"0")
                else:
                    codeword_book[huffman_tree[i][2][1]] = string+"0"
                break

        return codeword_book
    
    def decode(self, encoded_message, codeword_book):
        #decode a message with symbols from the codeword book
        max_len = self.max_l(codeword_book)
        decoded_message = ""
        codeword_book2 = {}
        for key in codeword_book:
            codeword_book2[codeword_book[key]] = key
        decoded_message = self.find_letter(codeword_book2, encoded_message, decoded_message, max_len)

        return decoded_message

    def max_l(self, codeword_book):
        #compute the maxium length of a code in the codeword book
        max_len = 0
        for key in codeword_book:
            l_c = len(codeword_book[key])
            if (l_c > max_len): max_len = l_c
        return max_len

    def find_letter(self, codeword_book2, encoded_message, decoded_message, max_len):
        #make strings up-to the maxium length of a code in the codeword book
        #check to see if the string is a code in the codeword_book if so
        #decode the code using the corresponding symbol for that code
        
        while len(encoded_message) > 0:  
            for i in range(max_len):
                code = encoded_message[:i+1]
                if code in codeword_book2: 
                    decoded_message += codeword_book2[code]
                    encoded_message = encoded_message[i+1:]
                    break
                
        return decoded_message

    def analysis(self, codeword_book, seq_of_outcomes, num_outcomes, t, encoded_size):
        #print the information associated with a symbol
        
        m_entropy = 0
        weighted_average_codeword_length = 0
        str_ = ""
        """\n\nInformation about each symbol:"
        str_ += "symbol               : the symbol from the origional message"
        str_ += "probability          : the frequency of the event divided by the number of events (length of message)"
        str_ += "codeword             : the binary representation create for the symbol using huffman"
        str_ += "length of codeword   : the length of the codeword"
        str_ += "weighted path length : the probaility times the length of the codeword"
        str_ += "probability budget   : the negative length of the codeword rasied to the power of two"
        str_ += "self_information     : the negative log of the probability of the symbol"
        str_ += "entropy              : the probability times the self-information\n"""
        
        for symbol_info in seq_of_outcomes:
            code = codeword_book[symbol_info[1]]
            l_code = len(code)
            prob_x = self.prob(symbol_info[0], num_outcomes)
            weighted_average_codeword_length += self.weighted_path_length(l_code, prob_x)
            m_entropy += self.entropy(prob_x)
            #str_ += "...\n"
            """str_ += symbol_info[1] + ","
            str_ += str(prob_x) + ","
            str_ += str(code) + ","
            str_ += str(l_code)  + ","
            str_ += str(self.weighted_path_length(l_code, prob_x)) + ","
            str_ += str(self.probability_budget(l_code)) + ","
            str_ += str(self.self_information(prob_x)) + ","
            str_ += str(self.entropy(prob_x)) + "\n" """
            
        #entropy of the message is the weighted sum of the information content of each symbol
       
        str_ += str(m_entropy) + "\n"
        str_ += str(m_entropy/num_outcomes) + "\n"
        str_ += str(8*num_outcomes) + "\n"
                
        str_ += str(weighted_average_codeword_length) + "\n"
        str_ += str(weighted_average_codeword_length/num_outcomes) + "\n"
        str_ += str(encoded_size) + "\n"
        str_ += str(encoded_size/8) + "\n"
        
        str_ += str((8*num_outcomes/float(encoded_size)-1)/8*num_outcomes/float(encoded_size)*100) + "\n"
        str_ += str(8*num_outcomes) + ":" + str(encoded_size) + "\n"
        str_ += str(8*num_outcomes/float(encoded_size)) + ":1\n"
        str_ += str(t)
        
        """str_ += " \n\nShannon's source coding theorem, says the entropy is a measure \n\
    of the smallest codeword length that is theoretically possible for the given alphabet \n\
    with associated probabilities. \n\
    The ratio is the #bits required before 
    Metric entropy will help you to assess the randomness of your message. It can take values from 0 to 1, where 1 means equally distributed random string.
    The metric entropy or Kolmogorov entropy is the shannon entropy divided by the length of the message\n

    So not only is this code optimal in the sense that no other feasible code performs better, \n\
    but it is very close to the theoretical limit established by Shannon." """
        return str_
    
    def weighted_path_length(self, l_code, p_x):
        return l_code * p_x

    def probability_budget(self, l_code):
        return 2**(-l_code)

    def prob(self, num_ways_event_occurs, num_outcomes):
        #compute the probability of an event
        
        #Probability is the measure of how likely an event is
        #An event is one or more outcomes of an experiment
        #An outcome is the result of a single trial of an experiment
        #An experiment is a situation involving chance or probability
        #that leads to results called outcomes.
        return float(num_ways_event_occurs)/ num_outcomes
        
    def self_information(self, prob_x):
        #compute the self-information of an event
        
        #self-information is a measure of the information content
        #associated with the outcome of a random variable
        return -(math.log(prob_x, 2))

    def entropy(self, prob_x):
        #compute the entropy of the symbols and the message
        
        if (prob_x == 0):
            #by definition the entropy of an event = 0 is 0 
            entropy_x = 0
        else:
            entropy_x = (prob_x*self.self_information(prob_x))
        return entropy_x
     
        
        
class Arithmetic:
    def __init__(self, info, file_): #Arithmetic(info[message, frequencies, symbols], filename)
        """ the NODE class constructor """
        self.c = []
        self.d = []
        info[0] = info[0] + "\0" #add eof to message
        info[1] = [1] + info[1]  #add eof frequency
        info[2] = ["\0"] + info[2]#add eof symbol
        self.message = info[0]
        self.r = len(self.message)
        """if self.r != sum(info[1]):
            print "freq mismatch" """
        self.symbols = info[2]
        self.frequencies = info[1]
        self.precision = 32
        self.whole = 2**self.precision
        self.half = self.whole / 2
        self.quarter = self.whole / 4
        self.encoded_message = ""
        self.decoded_message = ""
        self.setup()
        #return
        start = datetime.datetime.now()
        print "encoding arithmetic..."
        self.encode()
        end = datetime.datetime.now()
        t = end - start
        print t
        file_ = open(file_, 'w')
        file_.write(self.analysis(t))
        file_.close()
        
        
        """
        print "decoding..."
        self.decode()
        #print self.message
        #print self.decoded_message
       
        if self.decoded_message != info[0]:
            print "Error with Arithmetic algorithms!"
        else:
            print "Algorithms successful!" """
        #print "a done"
        
        

    def setup(self):
        #compute c,d
        self.c.append(0)
        self.d.append(self.frequencies[0])
        for j in range(1, len(self.frequencies)):
            sum1 = 0
            for i in range(j):
                sum1 += self.frequencies[i]
            self.c.append(sum1)
            self.d.append(sum1+self.frequencies[j])

        """print "s: ", self.symbols
        print "f: ", self.frequencies
        print "c: ", self.c
        print "d: ", self.d"""

    def encode(self):
        a = 0
        b = self.whole
        s = 0
        
        for i in range(len(self.message)):
            #print "symbol", self.message[i]
            
            """print "d", self.d[int(self.message[i])]
            print "c", self.c[int(self.message[i])]"""
            w = b - a
            index = self.symbols.index(self.message[i])
            b = a + (w * self.d[index] / self.r)
            a = a + (w * self.c[index] / self.r)
            """print "a", a
            print "b", b"""
            while b < self.half or a > self.half:
                if b < self.half:#zero case
                    self.encoded_message += "0"
                    a *= 2
                    b *= 2
                    for i in range(s):
                        self.encoded_message += "1"
                    s = 0
                if a > self.half:#1 case
                    self.encoded_message += "1"
                    a = 2 * (a - self.half)
                    b = 2 * (b - self.half)
                    for i in range(s):
                        self.encoded_message += "0"
                    s = 0
            while a > self.quarter and b < 3*self.quarter:#s case
                s += 1
                a = 2 * (a - self.quarter)
                b = 2 * (b - self.quarter)
        s += 1
        if a <= self.quarter: #case q
            self.encoded_message += "0"
            for i in range(s):
                self.encoded_message += "1"
        else:
            self.encoded_message += "1"
            for i in range(s):
                self.encoded_message += "0"

    def decode(self):
        a = 0
        b = self.whole
        z = 0
        i = 1
        
        
        #print len(self.encoded_message)
        while i <= self.precision and i <= len(self.encoded_message):
            if int(self.encoded_message[i-1]) == 1:
                z = z + 2**(self.precision - i)
            i += 1
        """print "q:", self.quarter, "   ", bin(self.half)
        print "h:", self.half, "   ", bin(self.half)
        print "w:", self.whole, "   ", bin(self.whole)
        print "p:", self.precision"""
        while 1:
            for j in range(len(self.symbols)):
                #print "decoding"
                w = b - a
                b0 = a + (w * self.d[j] / self.r)
                a0 = a + (w * self.c[j] / self.r)
                
                
                if a0 <= z and z < b0:
                    #print "...1"
                    self.decoded_message += str(self.symbols[j])
                    """print "j :", j
                    print "a :", a, "   ", bin(a)
                    print "b :", b, "   ", bin(b)
                    print "a0:", a0, "   ", bin(a0)
                    print "b0:", b0, "   ", bin(b0)
                    print "z :", z, "   ", bin(z)
                    print self.message
                    print self.decoded_message
                    print self.encoded_message"""
                    a = a0
                    b = b0
                    
                    if str(self.symbols[j]) == "\0":
                        return
                    break
                
            while b < self.half or a > self.half:
                #print "...2"
                if b < self.half:
                    #print "...3"
                    #print "in 0 case"
                    a = 2 * a
                    b = 2 * b
                    z = 2 * z
                elif a > self.half:
                    #print "...4"
                    #print "in 1 case"
                    a = 2 * (a - self.half)
                    b = 2 * (b - self.half)
                    z = 2 * (z - self.half)
                if i <= len(self.encoded_message) and int(self.encoded_message[i-1]) == 1:
                    #print "...5"
                    z += 1
                i += 1
            
            while a > self.quarter and b < 3 * self.quarter:
                #print "...6"
                a = 2 * (a - self.quarter)
                b = 2 * (b - self.quarter)
                z = 2 * (z - self.quarter)
                if i <= len(self.encoded_message) and int(self.encoded_message[i-1]) == 1:
                    #print "...7"
                    z += 1
                i += 1
                
    def analysis(self, t):
        total_outcomes = sum(self.frequencies)
        l = 0
        for outcome in self.frequencies:
            px = float(outcome) / float(total_outcomes)
            lx = math.ceil(-(math.log(px, 2))) + 1
            l += px * lx
        str_ = str(l) + "\n"
        str_ += str(l/total_outcomes) + "\n"
        str_ += str(len(self.encoded_message)) + "\n"
        str_ += str(len(self.encoded_message)/8) + "\n"
        str_ += str((8*len(self.message)/float(len(self.encoded_message))-1)/8*len(self.message)/float(len(self.encoded_message))*100) + "\n"
        str_ += str(8*total_outcomes) + ":" + str(len(self.encoded_message)) + "\n"
        str_ += str(8*len(self.message)/float(len(self.encoded_message))) + ":1\n"
        str_ += str(t)
        return str_
        
class Experiment:
    def __init__(self):
        """
        run the experiment
        """
        start = datetime.datetime.now().replace(microsecond=0)
        self.run()
        end = datetime.datetime.now().replace(microsecond=0)
        t = end - start
        print t

    def read_message(self, file_):
        #read the file to create the message as a string 
        message = ""
        while 1:
            line = file_.readline()
            if not line:
                break
            message += line
        m = message.translate(None,  "".join(c for c in message if not c in (string.ascii_letters+string.digits))) 
        return [(m[:150000]).lower(), m]
        #(m[:238620]).lower() #225000->3:58 350000->11:20 175000->1:59

    def frequency_dictionary(self, message):
        #create a dictionary of the frequency of each symbol
        letter_dict = {}
        for i in message:
            if letter_dict.has_key(i):
                letter_dict[i] += 1
            else:
                letter_dict[i] = 1
        return letter_dict

    def setup(self, file_, option = 'f', file2_ = None):
        """
        1. Read the file and clean-up the message to contain only characters and spaces
        2. Create a dictionary of symbols with the frequency of the symbol
        3. Create a list of symbols and put them into lexigraphical order,
        4. Create a corresponding list of the frequencies
        5. The function returns a list of the message, frequencies corresponding
           to symbols in order, and symbols in order
        """
        if option == 'f':
            message = self.read_message(file_)
            message2 = message[1]
            message = message[0]
        else:
            message = file_
            message2 = file2_
        frequency_dict = self.frequency_dictionary(message)
        #print frequency_dict
        symbols = frequency_dict.keys()
        symbols.sort()
        frequencies = []
        for symbol in symbols:
            frequencies.append(frequency_dict[symbol])

        frequency_dict2 = self.frequency_dictionary(message2)
        #print frequency_dict
        symbols2 = frequency_dict2.keys()
        symbols2.sort()
        frequencies2 = []
        for symbol in symbols2:
            frequencies2.append(frequency_dict2[symbol])
            
        return [[message, frequencies, symbols], [message2, frequencies2, symbols2]]

    def run(self):
        """
        1. known group is a list of all the books
           that need to have the author determined
        2. unknown group is the list of all books where
           the author is known
        3. start is a flag that is used to determine if this
           is first time the inner loop is encountered so that
           these books are not compressed more times than they
           are needed to be
        """
        """
        file_ = open("DavidCopperfield.txt")#LoveAndOtherStories
        info = self.setup(file_)
        file_.close()
        huffman = Huffman(info, "DavidCopperfield_h_k.txt")
        arithmetic = Arithmetic(info, "DavidCopperfield_a_k.txt")
        """
        known_group = ["TakenByTheEnemy2"]
        unknown_group = ["ThroughTheLooking-Glass4"]
        
        for i in range(len(known_group)):
            #count += 1
            #open file at index i
            file_ = open(known_group[i] + ".txt")
            info1 = self.setup(file_) #create a message, list of symbols, list of frequencies
            file_.close()  
            
            #encode message with huffman and arithmetic and analysis
            book1 = known_group[i]
            #books += [book1 + "_h_k.txt", book1 + "_a_k.txt"]
            #huffman = Huffman(copy.copy(info1[1]), book1 + "_B_k.txt") #Huffman(info[message, frequency_dict], filename to be written to)
            #huffman = Huffman(copy.copy(info1[0]), book1 + "_h_k.txt") #Huffman(info[message, frequency_dict], filename to be written to)
            #arithmetic = Arithmetic(copy.copy(info1[0]), book1 + "_a_k.txt") #Arithmetic(message, file to be written to)
            
            for j in range(len(unknown_group)):
                #open file at index j
                file_ = open(unknown_group[j] + ".txt")
                info2 = self.setup(file_) #create a message, list of symbols, list of frequencies
                file_.close()  
               
                #concatinate message1 and message2 to create message3
                info3 = self.setup(info1[0][0]+info2[0][0], 'm', info1[1][0]+info2[1][0])
                #encode message with huffman and arithmetic and analysis
                book3 = known_group[i] + "_" + unknown_group[j]
                #books += [book3 + "_h_c.txt", book3 + "_a_c.txt"]
                huffman = Huffman(copy.copy(info3[1]), book3 + "_B_k.txt") 
                huffman = Huffman(copy.copy(info3[0]), book3 + "_h_c.txt") #Huffman(info[message, frequency_dict], filename to be written to)
                arithmetic = Arithmetic(copy.copy(info3[0]), book3 + "_a_c.txt") #Arithmetic(message, file to be written to)
                
            start = False
        #print count


e = Experiment()
