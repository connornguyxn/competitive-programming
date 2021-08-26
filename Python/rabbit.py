months = int(input('How many months?: '))
months_count, rabbits_count = 0, 0
n1, n2 = 1, 1
while (months_count < months):
       nth = n1 + n2
       n1 = n2
       n2 = nth
       months_count += 1
print('Number of rabbits: ' + str(n1))