class Branch:
    def __init__(self,name,data=[],status=""):
        self.name=name
        self.status=status # M U * M: means Modified * U: means Uploaded
        self.data=data # list off data can bee added 
    def __repr__(self):
        return f"{self.name},{self.data }"
    def add_data(self,new_data:str):
        self.data.append(new_data)
branchs=[]# list of branches and  there data
try:
    _inpt=int(input(""))
except:
    print("NO")
    exit(0)

while _inpt>0:
    inp=input("").split()
    branch= inp[0]
    data=inp[1:]
    # data="".join(inp.split()[1:]).replace(' ','')    
    names=[j.name for j in branchs]
    if str(branch) in names:
        # brach created 
        index=names.index(str(branch))
        branchs[index].add_data("".join(data))
    else:
        branchs.append(Branch(branch,[''.join(data)]))
    _inpt-=1

#### testing ####
# b_main=Branch("Main",['A B D'])
# b_main.add_data('5 3 2')
# b_A=Branch("A",['A B C D'])
# b_A.add_data("5 3 2")
# b_B=Branch("B",['K I J'])

# branchs=[b_main,b_A,b_B]
# y_data=['ABCD','532','HIK']
out=[]

main_data=branchs[0].data
other_branches_data=[]
for i in [i.data for i in branchs[1:]]:
    for j in i:
        other_branches_data.append(j)
#non modified
x=set(other_branches_data).intersection(main_data)
for k in list(x):
    main_data.remove(k)    

y_data=set(other_branches_data)-x # remove inmodified element

# if any(elem in list(main_data)  for elem in list(y_data)):
for j in list(y_data):

    if j[0] in [s[0] for s in main_data]:
        #modified data
        out.append(j+" : M")# unmodified
    else:
        out.append(j+" : U")# uploaded

    
out.append("".join(([''.join(f) for f in list(x)])))# unmodified


for i in out:
    print(i)
  