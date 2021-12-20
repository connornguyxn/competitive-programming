#coded w/ <3 by inf1nity
#b1
m = int(input())
n = int(input())
t = 0
for i in range(m,n+1):
    if (i%3==0) or (i%5==0):
        t += i
print(t)

#b2
a = 0
while a<=0:
    a = int(input())
print(a)