from os.path import exists

with open('lib/template.cpp', 'r') as f:
    template_lines = f.read().splitlines()

newfile_lines = []
newfile_name = input(f'Enter filename: ')

problem_name = newfile_name.split('_')[-1]

placeholders = {
    '<problem link>': newfile_name,
    '<task name>': problem_name,
}

for line in template_lines:
    for placeholder, content in placeholders.items():
        line = line.replace(placeholder, content)
    
    if line.count('//!'):
        line = line.replace('//!', '//')
    else:
        if (line.count('//')):
            line = line[:line.find('//')].rstrip()
            if line == '':
                continue
    
    if line.rstrip() != '':
        line = line.rstrip()
    
    newfile_lines.append(line)



if (exists(newfile_name + '.cpp')):
    inp = input('File exists. Overwrite? (y/n): ')
    if (inp == 'y'):
        with open(newfile_name + '.cpp', 'w') as f:
            f.write('\n'.join(newfile_lines))
else:
    with open(newfile_name + '.cpp', 'w') as f:
        f.write('\n'.join(newfile_lines))