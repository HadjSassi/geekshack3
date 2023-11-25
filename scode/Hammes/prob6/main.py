n=int(input())
ch=input()
code=ch.split(" ")[0];
ch=ch.split(" ")[1];
def reverse_for_loop(s):
    s1 = ''
    for c in s:
        s1 = c + s1  # appending chars in reverse order
    return s1
for num in reversed(range(len(ch)+1)):
    if(n%(num+1)==0):
        ch[::num+1]=reverse_for_loop(ch[::num+1])
print(ch)