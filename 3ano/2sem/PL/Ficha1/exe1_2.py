import re
line1 = "hello world"
line2 = "goodbye world"
line3 = "hi, hello there"
line4 = "<Ola>, </Hello>, outrpo tedxto <adeus>, </hello> there! <hello>, girls!! </hello>, guys!!!"
line5 = ""

#res = re.search(r'(?i:hello)', line1)
#res = re.search(r'(?i:hello)', line2)
#res = re.search(r'(?i:hello)', line3)
#res = re.findall(r'(?i:(<>))', line4)
#res = re.findall(r'<[^>]+>', line4)
#res = re.findall(r'(<.*>|</.*>)', line4)
#res = re.findall (r"</?(.+?)>", line4)
res = re.sub(r"</?(.+?)>", "", line4)

#res = re.search(r'[a-zA-Z]+', line5)

if res:
  print(res)
else:
  print("Não encontrei nada!")



