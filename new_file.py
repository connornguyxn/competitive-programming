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

problem_link = input(f'Problem: ')
newfile_name = problem_link.split('/')[-1]

for site, prefix in site_prefixes.items():
    if site in problem_link:
        newfile_name = prefix + '_' + newfile_name
        break

is_judge = newfile_name[-1] == '_'
if is_judge:
    print('Judge file detected.')
    newfile_name = newfile_name[:-1]

placeholders = {
    '<problem link>': problem_link,
    '<task>': newfile_name,
}

def parse(template_lines):
    newfile_lines = []
    
    for line in template_lines:
        for placeholder, content in placeholders.items():
            line = line.replace(placeholder, content)
        
        if line.count('//!'):
            line = line.replace('//!', '//')
        else:
            if (line.count('///') == 0 and line.count('//')):
                line = line[:line.find('//')].rstrip()
                if line == '':
                    continue
        
        if line.rstrip() != '':
            line = line.rstrip()

        newfile_lines.append(line)
    
    return newfile_lines

def readlines(file_path):
    return parse(open(file_path, 'r').read().splitlines())

def create_file(file_path, file_lines):
    print(f'File path: {file_path}')
    if os.path.exists(file_path):
        response = input(f'{file_path} already exists. Overwrite? (y/n): ')
        if response.lower() != 'y':
            print('Operation cancelled.')
            return
    with open(file_path, 'w') as f:
        f.write('\n'.join(file_lines))

def makedir(workspace_path):
    if os.path.exists(workspace_path):
        response = input(f'Folder {workspace_path} already exists. Continue? (y/n): ')
        if response.lower() != 'y':
            print('Operation cancelled.')
            exit()
    os.makedirs(workspace_path, exist_ok=True)


workspace_path = 'workspace'
templates_path = 'templates'

if is_judge:
    judge_lines = readlines(f'{templates_path}/judge.cpp')
    create_file(f'{workspace_path}/{newfile_name}_judge.cpp', judge_lines)
else:
    template_lines = readlines(f'{templates_path}/template.cpp')
    
    folder_path = f'{workspace_path}/{newfile_name}'
    makedir(folder_path)
    
    file_basepath = f'{folder_path}/{newfile_name}'
    create_file(file_basepath + '.cpp', template_lines)
    create_file(file_basepath + '.inp', [])
    create_file(file_basepath + '.ans', [])