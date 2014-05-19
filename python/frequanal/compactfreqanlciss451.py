
import urllib
import string
import time
beg=7500
for part in range(12500,16001,500):
    gram_dic = {}
    total = 0
    for i in range(part,part+500):
        print "next 500"
        try:
            start = time.clock()
            s = "http://www.gutenberg.org/cache/epub/%s/pg%s.txt" %(i, i)
            s = urllib.urlopen(s).read()
            
            if s.find("Language: English")>0:
                t = ""
                for char in s:
                    if string.ascii_letters.find(char) >= 0:
                        t += char
                s = t
                s = s.lower()
                s_len = len(s)
                #print "i  ", i, "   len of s  ", s_len
                total += s_len
                #print "3"
                for number in range((s_len-5)):
                    #if number % 10000 == 0: print "number:", number
                    for next in range(1, 4):
                        substring = s[number:number+next]
                        if gram_dic.has_key(substring):
                            gram_dic[substring] += 1
                            #print "dict for", substring, "...", gram_dic[substring]
                        else: gram_dic[substring] = 1
                end = time.clock()
                #print "time =", float(end - start)
                #print "4"
            
            

                
                
            else:
                #print "forbidden file"
                pass
            
        except:
            print "not valid"
    gram_dic['total_size'] = total
    #print "put in dict"
    
    filename = str(part) + 'guttenburgdatasample.txt'

    
    f = open(filename, 'w')
    for k, v in gram_dic.iteritems():
        #print k, v
        f.write((str(k)+' '+str(v)+'\n'))
    f.close
