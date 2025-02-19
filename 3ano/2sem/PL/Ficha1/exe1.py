# Exercício 1.1
def starts_with_hello(line):
    return re.match(r'^hello', line) is not None

print(starts_with_hello(line1))  # True
print(starts_with_hello(line2))  # False
print(starts_with_hello(line3))  # False

def wherever_with_hello (line):
    return re.search(r"hello+?", line) is not None

def MaiMin (line):
    return re.findall(r"hello+?|HELLO+?") is not None