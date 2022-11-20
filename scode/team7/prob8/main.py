class Solution(object):
   def largestRectangleArea(self, heights):
      stack = []
      i = 0
      ans = 0
      while i < len(heights):
         if len(stack) == 0 or heights[stack[-1]]<=heights[i]:
            stack.append(i)
            i+=1
         else:
            x = stack[-1]
            stack.pop()
            height = heights[x]
            temp = height * (i-stack[-1]-1) if len(stack)!= 0 else height * i
            ans = max(ans,temp)
      while len(stack)>0:
         x = stack[-1]
         height = heights[x]
         stack.pop()
         temp = height * (len(heights)-stack[-1]-1) if len(stack)!= 0 else height* len(heights)
         ans = max(ans,temp)
      return ans
ob = Solution()
print(ob.largestRectangleArea([1,3,2,4])) 