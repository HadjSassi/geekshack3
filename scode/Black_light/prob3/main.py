s=input()
nb=0
def count_delicious_substrings(s):
    count = 0
    for i in range(len(s)):
        for j in range(i + 7, len(s) + 1):
            if s[i:j].startswith('chak') and s[i:j].endswith('chouka'):
                count += 1
    return count
nb=count_delicious_substrings(s) 
print(nb)
    
    
          

         