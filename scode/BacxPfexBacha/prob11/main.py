t=int(input())
for i in range(t):
   ch=input()
   ch=ch.split(" ")
   ch2=input()
   ch2=ch2.split(" ")
  # print(ch2)
   for x in range(len(ch2)):
      ans=0
      for y in range(len(ch)):
        a=(int)(ch2[x])
        b=(int)(ch[y])
        ans+=b*pow(a,len(ch)-y-1)
      if(x!=len(ch2)-1):
       print(ans,end=" ")
      else:
       print(ans)
   print()  