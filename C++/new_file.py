#!/bin/python3
from os.path import exists

with open('_template.cpp', 'r') as f:
    template_lines = f.read().splitlines()

newfile_lines = []
newfile_name = ''.join(input('name: ').lower().split())


wildcard_lines = {
    '// <problem link>': '',
    '// <tags>': '',
    # '// ifstream cin("_input");': '',
    # '// ofstream cout("_output");': '',
    # '// freopen(TASK".inp", "r", stdin)': '',
    # '// freopen(TASK".out", "w", stdout);': '',
}

placeholders = {
    "<task name>": newfile_name.split('_')[-1]
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
        
    for placeholder in placeholders:
        line = line.replace(placeholder, placeholders[placeholder])
        
    newfile_lines.append(line.rstrip())
    

if (exists(newfile_name + '.cpp')):
    inp = input('File exists. Overwrite? (y/n): ')
    if (inp == 'y'):
        with open(newfile_name + '.cpp', 'w') as f:
            f.write('\n'.join(newfile_lines))
else:
    with open(newfile_name + '.cpp', 'w') as f:
        f.write('\n'.join(newfile_lines))