import os

problem = input(">")
cwd = os.getcwd() + f'/{problem}/'

items = os.listdir(cwd)
files = [item for item in items if os.path.isfile(os.path.join(cwd, item))]

ext = {
    'i': 'inp',
    'o': 'out',
}

for file in files:
    idx, typ = file.split('.')
    if (typ not in ext):
        continue
    testfolder = 'test' + idx.zfill(3) + '/';
    if not (os.path.exists(cwd + testfolder)):
        os.mkdir(cwd + testfolder)
    os.rename(cwd + file, cwd + testfolder + problem + '.' + ext[typ])