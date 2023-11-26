ch = input()
lista = []
for i in range(int(ch[0])):
   lista.append(input().split(' '))


if lista.count(1)==4:
    print(1)
elif lista.count(2)==4:
    print(2)
elif lista.count(0)==4:
    print(0)  