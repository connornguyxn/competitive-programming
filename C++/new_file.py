from os.path import exists

with open('lib/template.cpp', 'r') as f:
    template_lines = f.read().splitlines()

newfile_lines = []
choice = int(input('Link (1) or File (2): '))
problem_link = input(f'Your choice was {choice}\nEnter {["link", "filename"][choice - 1]}: ').replace('https://', '')

problem_prefixes = {
    'vnoi': 'vnoj',
    'ntucoder': 'ntuc',
    'ucode': 'ucode',
    'lqdoj': 'lqdoj'
}

if (choice == 1):
    newfile_name = problem_link.split('/')[-1]
    
    for prefix in problem_prefixes:
        if problem_link.find(prefix) != -1:
            newfile_name = problem_prefixes[prefix] + '_' + newfile_name
            break
    else:
        newfile_name = problem_link.split('/')[0].replace('.', '') + '_' + newfile_name
    problem_name = newfile_name.split('_')[-1]
else:
    problem_name = problem_link
    newfile_name = problem_name
newfile_name = newfile_name.lower()


placeholders = {
    '<problem link>': problem_link,
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