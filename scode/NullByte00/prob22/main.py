s = input()
# s = "mbappe"
if len(s)==1:
    print(s)
    exit()
def check_pal(s):
    for i in s:
        if s.count(i)%2:
            return False
    return True 

added = {}
count = {i: s.count(i) for i in s}
for i in count:
    if count[i]%2 == 0:
        added[i] = count[i]
        s = s.replace(i ,"")

l = list(s)
l.sort(reverse=True)
# print(l)
# print(l)
for i in range(len(l)//2):
    l[i] = l[-i-1]
    if check_pal("".join(l)):
        break
# print(l)

# new = "".join(l)
st = "".join(l)
for i in st:
    added[i]=st.count(i)
new=""
sorted_to_add_list = sorted(added.keys(), reverse=True)
# print(sorted_to_add_list)
for i in sorted_to_add_list:
    new = i*(added[i]//2) + new + i*(added[i]//2)
    
print(new)
# for i in added:
# print(added)
# print(count)