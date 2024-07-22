from random import randint
import random as rd
import os

testcase = 0
def generate(count, gen_func):
    global testcase
    for _ in range(count):
        testcase += 1
        print(f'Generating test {testcase}:')
        
        print('Generating input...')
        with open(f'{problem}.inp', 'w') as inp:
            gen_func(inp)
        
        
        print('Running solution...')
        os.system(f'{problem}.exe')
        
        
        print('Moving files...')
        folder = f'{problem}_test/{testcase}/'
        os.makedirs(folder, exist_ok=True)
        os.rename(f'{problem}.inp', f'{folder}{problem}.inp')
        os.rename(f'{problem}.out', f'{folder}{problem}.out')
        
        print('Done!\n')

def randint_biased(a, b, c, d, chance=0.5):
    return randint(a, b) if rd.random() < chance else randint(c, d)



problem = 'loverivals'