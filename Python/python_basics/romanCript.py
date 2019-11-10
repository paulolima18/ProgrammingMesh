def encript(string,key):#code a certain message (key = times moved)
    library = (('a','z'),('A','P'),('0','9'),(' ','/'))
    new_string = ""
    for old_c in string:
        for lib_c in library:
            n_chars = ord(lib_c[1]) - ord(lib_c[0]) + 1 #number of chars in sequence
            if old_c >= lib_c[0] and old_c <= lib_c[1]:
                new_string += chr(((ord(old_c) - ord(lib_c[0])+ key) % (n_chars)+ord(lib_c[0])))
                #(n_chars)+ord(lib_c[0]) -> set limit for char
                #(ord(old_c) - ord(lib_c[0])+ key) -> number of char to move
    return new_string

def decript(string,key):#solve code by going backward(need to know key)
    return encript(string,-key)

if __name__ == "__main__":
    word = "xyzXYZ789"
    key = 3
    coded = encript(word,key) #Expected: abcABC012
    print(coded)
    decoded = decript(coded,key)
    print(decoded)
