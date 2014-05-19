import string
import math
import copy

def dict_list(letter_dict):
    #create a list from a dictionary
    seq_of_outcomes = []
    for key, value in letter_dict.iteritems():
        temp = [value, key]
        seq_of_outcomes.append(temp)
    return seq_of_outcomes

def frequency_dictionary(message):
    #create a dictionary of the frequency of each symbol
    letter_dict = {}
    for i in message:
        if letter_dict.has_key(i):
            letter_dict[i] += 1
        else:
            letter_dict[i] = 1
    return letter_dict

def analysis(codeword_book, seq_of_outcomes, num_outcomes):
    #print the information associated with a symbol

    m_entropy = 0
    weighted_average_codeword_length = 0
    print "\n\nInformation about each symbol:"
    print "symbol               : the symbol from the origional message"
    print "probability          : the frequency of the event divided by the number of events (length of message)"
    print "codeword             : the binary representation create for the symbol using huffman"
    print "length of codeword   : the length of the codeword"
    print "weighted path length : the probaility times the length of the codeword"
    print "probability budget   : the negative length of the codeword rasied to the power of two"
    print "self_information     : the negative log of the probability of the symbol"
    print "entropy              : the probability times the self-information\n"
    for symbol_info in seq_of_outcomes:
        code = codeword_book[symbol_info[1]]
        l_code = len(code)
        prob_x = prob(symbol_info[0], num_outcomes)
        weighted_average_codeword_length += weighted_path_length(l_code, prob_x)
        m_entropy += entropy(prob_x)
        print "symbol               :\'%s\'" % symbol_info[1]
        print "probability          :", prob_x
        print "codeword             :", code
        print "lenght of codeword   :", l_code 
        print "weighted path length :", weighted_path_length(l_code, prob_x)
        print "probability budget   :", probability_budget(l_code)
        print "self_information     :", self_information(prob_x)
        print "entropy              :", entropy(prob_x), "\n"
        
    #entropy of the message is the weighted sum of the information content of each symbol
    print "\nEntropy of the message (the entropy of all the symbols combined)...", m_entropy
    print "\nWeighted average codeword length of the message (the weighted path length of all \
the symbols combined)...",  weighted_average_codeword_length
    print " \n\nShannon's source coding theorem, says the entropy is a measure \n\
of the smallest codeword length that is theoretically possible for the given alphabet \n\
with associated probabilities. \n\
So not only is this code optimal in the sense that no other feasible code performs better, \n\
but it is very close to the theoretical limit established by Shannon."

"""/////////////////////////////////////////////////////
Function to calculate probability, self-info, and entropy
   ///////////////////////////////////////////////////// """
def weighted_path_length(l_code, p_x):
    return l_code * p_x

def probability_budget(l_code):
    return 2**(-l_code)

def prob(num_ways_event_occurs, num_outcomes):
    #compute the probability of an event
    
    #Probability is the measure of how likely an event is
    #An event is one or more outcomes of an experiment
    #An outcome is the result of a single trial of an experiment
    #An experiment is a situation involving chance or probability
    #that leads to results called outcomes.
    return float(num_ways_event_occurs)/ num_outcomes
    
def self_information(prob_x):
    #compute the self-information of an event
    
    #self-information is a measure of the information content
    #associated with the outcome of a random variable
    return -(math.log(prob_x, 2))

def entropy(prob_x):
    #compute the entropy of the symbols and the message
    
    if (prob_x == 0):
        #by definition the entropy of an event = 0 is 0 
        entropy_x = 0
    else:
        entropy_x = (prob_x*self_information(prob_x))
    return entropy_x
     
"""/////////////////////////////////////////////////////
Functions to create the codeword book
   ///////////////////////////////////////////////////// """
def create_codeword_book_from_huffman_tree(alpha, string, huffman_tree, codeword_book):
    #from the root of the huffman tree create codes by appending 0 or 1 for each branch
    for i in range(len(huffman_tree)):
        #print "value...", huffman_tree[i]
        if huffman_tree[i][0][1] == alpha:
            if "alpha" in huffman_tree[i][1][1]:
                create_codeword_book_from_huffman_tree(huffman_tree[i][1][1], (string+"1"), huffman_tree, codeword_book)
                #print "here1..", huffman_tree[i][1][1], (string+"1")
                
            else:
                codeword_book[huffman_tree[i][1][1]] = string+"1"
            
        
            if "alpha" in huffman_tree[i][2][1]:
                create_codeword_book_from_huffman_tree(huffman_tree[i][2][1], (string+"0"), huffman_tree, codeword_book)
                #print "here2..", huffman_tree[i][2][1], (string+"0")
            else:
                codeword_book[huffman_tree[i][2][1]] = string+"0"
            break

    return codeword_book

def create_huffman_codeword_book(message, seq_of_outcomes):
    #create a huffman tree and then create a codeword book from the tree

    seq_of_outcomes = copy.copy(seq_of_outcomes)
    
    #we will handle the lowest frequency as a special case
    specialcase = min(seq_of_outcomes)

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
        
    print "\nHuffman tree as a list..." 
    for i in huffman_tree:
        print i
        
    codeword_book = {}
    
    codeword_book = create_codeword_book_from_huffman_tree(alpha, "", huffman_tree, codeword_book)
    return codeword_book



        
"""/////////////////////////////////////////////////////
Function to Encode the message
   ///////////////////////////////////////////////////// """
def encode(codeword_book, message):
    #encode a message with codes from the codeword book
    encoded_message = ""
    for symbol in message:
        encoded_message += codeword_book[symbol]
    return encoded_message


"""/////////////////////////////////////////////////////
Functions to Decode the message
   ///////////////////////////////////////////////////// """
def decode(codeword_book, encoded_message):
    #decode a message with symbols from the codeword book
    max_len = max_l(codeword_book)
    decoded_message = []
    codeword_book_items = codeword_book.items()
    find_letter(codeword_book_items, encoded_message, decoded_message, max_len)
    return decoded_message

def max_l(codeword_book):
    #compute the maxium length of a code in the codeword book
    max_len = 0
    for key in codeword_book:
        l_c = len(codeword_book[key])
        if (l_c > max_len): max_len = l_c
    return max_len

def find_letter(codeword_book_items, encoded_message, decoded_message, max_len):
    #make strings up-to the maxium length of a code in the codeword book
    #check to see if the string is a code in the codeword_book if so
    #decode the code using the corresponding symbol for that code
    for i in range(max_len):
        code = encoded_message[:i+1]
        for item in codeword_book_items:
            if (item[1] == code):
                decoded_message.append(item[0])
                find_letter(codeword_book_items, encoded_message[i+1:], decoded_message, max_len)

###########################################
#message = 'aaabbbccaabbcaaaa'
#message = 'goodgoodygoodday'
#message = 'jjjlllllldfdddff'
message = 'hello doctor liow how are you?'
#message = "kdnfkldnksdkkkksoe,xpqwaz"


print "Message...", message
print "Length of message...", len(message)
print "Distinct symbols in the message...", len(frequency_dictionary(message))

outcomes = dict_list(frequency_dictionary(message))
print "Sequence of outcomes...", outcomes

book = create_huffman_codeword_book(message, outcomes)
print "\nCodeword Book...\n", book

encoded_message = encode(book, message)
print "\nEncoded message...\n", encoded_message

decoded_message = decode(book, encoded_message)
print "\nDecoded message...\n", ''.join(decoded_message)


analysis(book, outcomes, len(message))
