try:
    line = int(input())
except:
    print('SYNTAX_ERROR')
    exit(0)
syntax={
    0:['[',']'],
    1:['{','}'],
    2:["'","'"],
    3:['(',')'],
    4:['"','"'],
    5:['`','`']
}
req=[
    r'\((.*?)\)', # find ()
    r'\{(.*?)\}',
    r'\'(.*?)\'',
    r'\[(.*?)\]',
    r'\`(.*?)\`',
    r'\"(.*?)\"',
]
# _in=input()
a="geeks('hack')(())ensit'info'glid"
b=[]
import re
def extract(aa):
    for i in req:
        m=re.search(i,aa)
        if m:
            res=m.group(0)
            print(res,aa)
            aa=aa.replace(res,'')
    # return extract(aa)
#extract(a)
extract(line)




 