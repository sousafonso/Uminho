import re
line1 = "Hello there! Uh, hi, hello, it's me... Heyyy, hello? HELLO!"
line2 = "O meu telemóvel é 954324028 ou 9684122875 ou 931212411. O dele é 203604468. O do zé é 150305152"
line3 = "Hello there! Uh, hi, hello, it's me... Heyyy, hello? HELLO!"

def reF(pattern, replacement, string):
  res = re.sub(pattern, replacement, string)
  return res

print(reF(r"(?i:hello)","*YEP*", line1)) # substitui "hello" por "*YEP*"
print(reF(r"[0-9]{9}", "*", line2)) # substitui os numeros de telemovel por "*"
print(reF(r"[29][0-9]{8}", "*", line2)) # substitui os numeros de telemovel por "*"
print(reF(r"(2[1-9][0-9]{7})|(9[1236][0-9]{7})", "++", line2)) # substitui os numeros de telemovel por "++"

print(re.sub(r"(?i:[a-zA-Z]+[,?!])","####", line3)) # substitui as primeiras 3 palavras por "####"
