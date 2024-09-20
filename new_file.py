import os

site_prefixes = {
    'codeforces': 'cf',
    'atcoder': 'atc',
    'topcoder': 'tc',
    'codechef': 'cc',
    'hackerrank': 'hr',
    'hackerearth': 'he',
    'spoj': 'spoj',
    'oj.vnoi': 'vnoj',
    'cses': 'cses',
    'leetcode': 'lc',
    'dmoj': 'dmoj',
    'lqdoj': 'lqdoj',
    'hnoj': 'hnoj'
}

with open('templates/template.cpp', 'r') as f:
    template_lines = f.read().splitlines()


problem_link = input(f'Enter problem link: ')
newfile_name = problem_link.split('/')[-1]

for site, prefix in site_prefixes.items():
    if site in problem_link:
        newfile_name = prefix + '_' + newfile_name
        break

print(newfile_name)


placeholders = {
    '<problem link>': problem_link,
    '<task>': newfile_name,
}


newfile_lines = []
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

if not os.path.exists(newfile_name):
    os.mkdir(newfile_name)



def create_files(filepath):
    with open(filepath + '.cpp', 'w') as f:
        f.write('\n'.join(newfile_lines))
    with open(filepath + '.inp', 'w') as f:
        f.close()

filepath = f'{newfile_name}/{newfile_name}'
if (os.path.exists(filepath)):
    inp = input('File exists. Overwrite? (y/n): ')
    if (inp == 'y'):
        create_files(filepath)
else:
    create_files(filepath)