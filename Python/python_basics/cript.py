def code(text):
    char_even = ""
    char_odd = ""
    char_sum = 0
    for char in text:
        if char_sum%2 == 0:
            char_even = char_even + char
        else:
            char_odd = char_odd + char
        char_sum+= 1
    text_coded = char_odd + char_even
    return text_coded

def decode(text):
    ip = len(text)//2
    odd = text[0:ip:]
    even = text[ip::]
    word = ""
    length = len(text)
    for i in range(length):
        if i%2 == 0:
            word+= even[0]
            even = even[1::]
        else:
            word+= odd[0]
            odd = odd[1::]
    return word

if __name__ == "__main__":
    string = "abcde"
    print("Original String:",string)
    cript = code(string)
    print("Coded String:",cript)
    final = decode(cript)
    print("Decoded String:",final)
