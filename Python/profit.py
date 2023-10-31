profit = int(input("This month's profit?"))
inc = 0

if (profit <= 100000):
    inc = 10
elif (profit <= 200000):
    inc = 7.5
elif (profit <= 400000):
    inc = 5
elif (profit <= 600000):
    inc = 3
elif (profit <= 1000000):
    inc = 1.5
else:
    inc = 1

print(profit * (inc / 100) + profit)