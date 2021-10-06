a = input()
puncs = [' ', ',', ':', ';', '.']
for punc in puncs:
    while a.find(' ' + punc) != -1:
        a = a.replace(' ' + punc, punc)
print(a.capitalize())