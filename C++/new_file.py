from os.path import exists

with open('_template.cpp', 'r') as f:
    template_lines = f.read().splitlines()

newfile_lines = []
choice = input('link(1) or file(2)? : ')
problem_link = input(f'your choice was {choice}\nenter text: ').replace('https://', '')

if (choice == '1'):
    problem_prefixes = {
        'vnoi': 'vnoj',
        'ntucoder': 'ntuc',
        'ucode': 'ucode',
        'lqdoj': 'lqdoj'
    }
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

wildcard = {
    '// <problem link>': f'// {problem_link}',
    '// <tags>': '',
    '<task name>': problem_name,
    # '// ifstream cin("_input");': '',
    # '// ofstream cout("_output");': '',
    # '// freopen(TASK".inp", "r", stdin)': '',
    # '// freopen(TASK".out", "w", stdout);': '',
}

exclude = [
    '        // freopen(TASK".out", "w", stdout);',
    '   // cin >> tc;'
]

for line in template_lines:
    if line in exclude:
        newfile_lines.append(line.rstrip())
        continue
    
    replaced = False
    
    for wc, txt in wildcard.items():
        if (line.count(wc)):
            replaced = True
            if (txt != ''):
                line = line.replace(wc, txt)
    
    if not replaced and line.strip().find('// ') == 0:
        continue
    if line.find(' // ') != -1 and len(line.split(' // ')):
        line = line[:line.find(' // ')]
    newfile_lines.append(line.rstrip())




if (exists(newfile_name + '.cpp')):
    inp = input('File exists. Overwrite? (y/n): ')
    if (inp == 'y'):
        with open(newfile_name + '.cpp', 'w') as f:
            f.write('\n'.join(newfile_lines))
else:
    with open(newfile_name + '.cpp', 'w') as f:
        f.write('\n'.join(newfile_lines))