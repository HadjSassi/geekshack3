from math import *
n = int(input())
l = list(map(lambda x:int(x),input().split()))
def solve(nums):
   if len(nums) == 1:
      return nums[0]

   div = gcd(nums[0], nums[1])

   if len(nums) == 2:
      return div

   for i in range(1, len(nums) - 1):
      div = gcd(div, nums[i + 1])
      if div == 1:
         return div
def premier(l,c) :
    k=0
    while l[k]!=c:
           k=k+1
    return k           
my_list = sorted(l)
l2=[]
l1=[]
change=my_list[0]
for i in range(len(my_list)):
    if premier(my_list,my_list[i])==i : 
        l1.append(l2)
        l2.clear()
    l2.append(my_list[i])
    
    
s=00
for i in range(len(l1)):
        sp=len(l1[i])*solve(l1[i])
        s=s+sp     
print(s)    
     