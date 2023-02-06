from requests import get
from tabulate import tabulate


with open('items.txt', 'r') as f:
    items = f.readlines()
with open('candidates.txt', 'r') as f:
    candidates = f.readlines()


def get_sequence(min, max):
    url = f'https://www.random.org/sequences/?min={min}&max={max}&col=1&format=plain&rnd=new'
    response = get(url)
    # format response to int list
    return [int(i) for i in response.text.split()]


# multiply each item of b to match items
b = candidates * (len(items) // len(candidates))
# shuffle b using random.org interger sequence generator
order = get_sequence(0, len(b) - 1)
b = [b[i] for i in order]


print(f'Remaining items: {len(items) - len(b)}')
if input('Randomize remaining items? (y/n) ') == 'y':
    # randomize remaining items
    order = get_sequence(0, len(candidates))
    for i in range(len(items) - len(b)):
        b.append(candidates[order[i]])


# match items and b and write to file
with open('match.txt', 'w') as f:
    f.write(tabulate(zip(items, b), tablefmt='plain'))
print('Results written to match.txt')