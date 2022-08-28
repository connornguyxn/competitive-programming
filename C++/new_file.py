#!/bin/python3

with open('_template.cpp', 'r') as f:
    template_lines = f.read().splitlines()

newfile_lines = []
newfile_name = ''.join(input('name: ').lower().split())


wildcard_lines = {
    '// <problem link>': '',
    '// <tags>': '',
    #'//ifstream cin("template.inp");': f'//ifstream cin("{newfile_name}.inp");',
    #'//ofstream cout("template.out");': f'//ofstream cout("{newfile_name}.out");',
}
for line in template_lines:
    if line.strip() in wildcard_lines:
        #print('wildcard line:', line)
        #print('replacing with:', wildcard_lines[line.strip()])
        if wildcard_lines[line.strip()] != '':
            line = line.replace(line.strip(), wildcard_lines[line.strip()])
        #print('new line:', line)
    elif line.strip().find('// ') != -1:
        if line.strip().find('// ') == 0:
            continue
        line = line[:line.find('//')]
    newfile_lines.append(line.rstrip())
with open(newfile_name + '.cpp', 'w') as f:
    f.write('\n'.join(newfile_lines))