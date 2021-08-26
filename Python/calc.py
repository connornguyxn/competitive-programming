a = input().split()
if a[1] == '+':
    print("{:.2f}".format(int(a[0])+int(a[2])))
elif a[1] == '-':
    print("{:.2f}".format(int(a[0])-int(a[2])))
elif a[1] == '*':
    print("{:.2f}".format(int(a[0])*int(a[2])))
elif a[1] == '/':
    print("{:.2f}".format(int(a[0])/int(a[2])))