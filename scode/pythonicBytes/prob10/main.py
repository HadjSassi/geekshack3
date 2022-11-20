try:
    n_users = int(input())
except:
    print('INPUT_ERROR')
    exit(0)
i=0
data=[]
while i<n_users:
    try:
        n_pouch,secondes = input().split()
        n= input().split()
        data.append([[n_pouch,secondes],n])
    except:
        print('NO')
        exit(0)
    i+=1

# get marge
ee=[]
for i in range(len(data)):
    for k in range(len(data[i][1])-1):
        ee.append([data[i][1][k],data[i][1][k+1]])


x=0

def calculate(n_,cred,_sec):
    # n_ : nbr of poush
    # cred : list()
    # _sec : int
    j=0
    s=0
    while j<int(n_)-1:

        if(int(cred[1])-int(cred[0])<int(_sec)):
            s+=int(cred[1])-int(cred[0])

        if(int(cred[1])-int(cred[0])>int(_sec)):
            s+=int(_sec)
        j+=1
    s+=int(_sec)
    return s
s_t=0
for t in range(n_users):
    s_t+=calculate(data[t][0][0],ee[t],data[t][0][1])
print(s_t) 