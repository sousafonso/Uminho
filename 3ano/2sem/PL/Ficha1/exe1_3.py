from re import *
line = "Hello there! Uh, hi, hello, it's me... Heyyy, hello? HELLO!"
line2 = "O meu telemóvel é 954324028 ou 9684122875 ou 931212411. O dele é 203604468. O do zé é 150305152"
#res = re.search(r'(?i:hello)', line1)

#res = findall(r'(?i:hello)', line)
testInput = input('>> ')
while testInput != '':
  res = findall(r'\d+', testInput)
  if res:
    print('Foram encontradas', len(res), 'ocorrências')
    for i in res:
      print(i)
  else:
    print("Nenhuma ocorrência")
  testInput = input('>> ')
