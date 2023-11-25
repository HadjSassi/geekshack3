ch=input()
m=0

for i in range(len(ch)-6):
    if 'chak' in ch[i:i+4]:
        m+=ch[i:].count('chouka')
        
print(m)
    