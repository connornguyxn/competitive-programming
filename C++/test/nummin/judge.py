import subprocess as subp

def test(testcase):
    with open('test.inp', 'w') as f:
        f.write(testcase)
    
    subp.run(['./solution.exe'])
    solution = open('test.out', 'r').read()
    
    subp.run(['./code.exe'])
    code = open('test.out', 'r').read()
    
    print('code:', code)
    print('solution:', solution)
    
    return solution == code

def main():
    for n in range(1, 1000):
        for k in range(1, 4):
            testcase = f'{n} {k}'
            print('testcase:', testcase)
            if test(testcase):
                print('accepted')
            else:
                print('wrong answer')
                return 0
            print()


if __name__ == '__main__':
    main()