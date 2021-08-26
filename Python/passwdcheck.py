import re

a = input()
if ((5 < len(a) < 18) and (re.search("[a-z]",a)) and  (re.search("[A-Z]",a)) and (re.search("[1-9]",a)) and (re.search("[$ # @]",a))):
    print('True')
else:
    print('False')
