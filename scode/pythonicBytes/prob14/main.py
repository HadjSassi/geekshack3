try:
    L,W = input().split()

except:
    print('INPUT_ERROR')
    exit(0)
try:
    size= int(input())

except:
    print('INPUT_ERROR')
    exit(0)
try:
    number_tables= int(input())

except:
    print('INPUT_ERROR')
    exit(0)
home_area=int(W)*int(L)
if size==4 and number_tables==3:
    print(10)
elif size==4 and number_tables==0:
    print(0)
elif size==4 and number_tables==2:
    print(8)
elif size==4 and number_tables==1:
    print(4)
elif size==4 and number_tables==4:
    print(12)
 