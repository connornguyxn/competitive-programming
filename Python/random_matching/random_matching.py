from requests import get
from tabulate import tabulate

with open('a.txt', 'r') as f:
    a = f.readlines()
with open('b.txt', 'r') as f:
    b = f.readlines()
req_url = 'https://www.random.org/integers/?num={}&min=0&max={}&col=1&base=10&format=plain&rnd=new'

# multiply each item of b to match a
b = b * (len(a) // len(b))
# shuffle b using random.org
url = req_url.format(len(b), len(b) - 1)
response = get(url)
b = [b[int(i)] for i in response.text.split()]

print(f'Remaining items: {len(a) - len(b)}')
if input('Randomize remaining items? (y/n) ') == 'y':
    # shuffle remaining items
    url = req_url.format(len(a) - len(b), len(a) - len(b))
    response = get(url)
    b += [b[int(i)] for i in response.text.split()]

# match a and b and write to file
with open('match.txt', 'w') as f:
    f.write(tabulate(zip(a, b), tablefmt='plain'))
print('Results written to match.txt')