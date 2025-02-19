import sys

ALFABETO = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def preproc(str):
    l = []
    for c in str:
        if c.isalpha():
            l.append(c.upper())
    return "".join(l)

def encrypt(key, text):
    result = ""
    for c in text:
        result += ALFABETO[(ALFABETO.index(c) + (ALFABETO.index(key.upper()) if isinstance(key, str) else key)) % len(ALFABETO)]
    return result

def decrypt(key, text):
    return encrypt(-key, text)

def main (args):
    key = args [2]
    text = args [3]

    if args[1] == "enc":
        print (encrypt((key), preproc(text)))
    elif args[1] == "dec":
        print (decrypt((key), preproc(text)))

if __name__ == "__main__":
    main(sys.argv)


