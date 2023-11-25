s = input()
som = 0

for i in range(len(s)):
    if (s[i:i+4] == 'chak'):

        x=s.count('chouka',i+4,len(s)+1)

        som =som + x

print(som)