from random import randint
import random as rd
import os

testcase = 0
inp = None

def generate(count, gen_func):
    global testcase, inp
    for _ in range(count):
        testcase += 1
        print(f'Generating test {testcase}:')
        
        
        print('Generating input...')
        inp = open(f'{problem}.inp', 'w')
        gen_func()
        inp.close()
        
        
        print('Running solution...')
        os.system(f'{problem}.exe')
        
        
        print('Moving files...')
        folder = f'{problem}_test/{testcase}/'
        os.makedirs(folder, exist_ok=True)
        os.rename(f'{problem}.inp', f'{folder}{problem}.inp')
        os.rename(f'{problem}.out', f'{folder}{problem}.out')
        
        print('Done!\n')

def printi(*args, **kwargs):
    global inp
    print(*args, **kwargs, file=inp)

def randint_biased(a, b, c, d, chance=0.5):
    return randint(a, b) if rd.random() < chance else randint(c, d)

problem = 'treasure'