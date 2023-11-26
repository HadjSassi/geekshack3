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


res = 0
l1= l.copy
for i in range(n):
   for j in range(i+1,n):
      if solve(l[i:j])!=1:
         res += (j-i)*solve(l[i:j])
print(res) 