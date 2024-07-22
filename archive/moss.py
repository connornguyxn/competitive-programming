import mosspy

problems = ['contest1', 'contest2', 'contest3', 'contest4']\

for problem in problems:
    moss = mosspy.Moss(136937988, 'cc')
    # moss = mosspy.Moss(74356531, 'cc')
    
    moss.addFilesByWildcard(f'submissions/*/codecampchv_{problem}.cpp')
    print(moss.files)
    
    url = moss.send()
    print(f"Report Url: {url}")
    
    moss.saveWebPage(url, f'{problem}.html')
