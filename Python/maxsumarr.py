#coded w/ <3 by inf1nity
input()
n = list(map(int, input().split(' ')))
k = int(input())
mx = 0
for i in range(len(n)-1):
    for j in range(i+1, len(n)):
        if sum(n[i:j])>mx and sum(n[i:j])<=k:
            mx = sum(n[i:j])
print(mx)