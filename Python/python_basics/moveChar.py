def moveChr(text,k):
    text_w=""
    for i in text:
        a = ord(i) + k%25
        if a > 122:
            a = a - 26
        text_w = text_w+chr(a)
    print(text_w)
"""
def moveChar(s,key):##better function
    s_new = ""
    n_chars = ord('z')-ord('a')
    for c in s:
        s_new = s_new + chr(((ord(c)-ord('a')+key)%n_chars+ord('a')))
    return s_new"""

if __name__=='__main__':
    moveChr("abc",1)
