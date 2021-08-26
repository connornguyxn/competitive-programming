a = input()
mn = a[0]
mx = a[0]
for i in a:
    if i>mx:
        mx = i
    if i<mn:
        mn = i
print('Min:', mn)
print('Max:', mx)