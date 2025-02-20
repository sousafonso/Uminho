from re import *

line1 = "HELLO worldo"
line2 = "goodbye world"
line3 = "hi, hello there"

res1 = match(r'([Hh][Ee][Ll][Ll][Oo])', line1)
if res1:
   print(res1)
   print(res1.group(0))

res2 = match(r'(?i:hello)', line2)
if res2:
  print(res2)
else:
  print("Não encontrei nada!")

res3 = match(r'(?i:h.{4,20}o)', line1)
if res3:
  print(res3.group(0))
else:
  print("Não encontrei nada!")