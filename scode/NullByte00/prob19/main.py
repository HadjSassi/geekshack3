import re

s = input().split()
cards = [i[1::] for i in s]

def atoi(text):
    return int(text) if text.isdigit() else text
#sorting using natural sort :: exp : C10 - C7
def natural_keys(text):
    return [ atoi(c) for c in re.split(r'(\d+)', text) ]

s.sort(key=natural_keys)
# print(s)
for i in range(len(cards)):
    if cards[i] in {'J', 'Q', 'K'}:
        cards[i] = 10
    elif cards[i] == 'A':
        cards[i] = 1

cards = [int(i) for i in cards]

somme = sum(cards)
if not somme>72:
    print("NO")
    exit()
    
s = [i[1::] for i in s]
for i in range(len(s)):
    if s[i] == 'J':
        s[i] = 11
    elif s[i] == 'Q':
        s[i] = 12
    elif s[i] == 'K':
        s[i] = 13
    elif s[i] == 'A':
        s[i] = 1
        
s = [int(i) for i in s]

score = 0
for i in range(len(s)-2):
    if s[i]+1 == s[i+1] and s[i+1]+1==s[i+2]:
        score+=s[i]*3 +2  

if score < 72 :
    print("NO")
else: 
    print("YES", somme)
  