def occ(fruitEaten):
    fruits = list(filter(lambda fruit: fruitEaten[fruit] == 1, fruitEaten))
    return len(fruits)
def get_keys_from_value(counter, val):
    return [k for k, v in counter.items() if v == val]
def nb(word):
    counter = {}
    for letter in word:
        counter[letter] = counter.get(letter, 0) + 1
    ch=set(word)
    nb=0
    for i in ch:
        if (counter[i]%2!=0 and (len(word)%2)==0) or ((len(word)%2)!=0 and occ(counter)>1):
            nb=-1

    a=get_keys_from_value(counter,1)
    if (len(word)%2)!=0:
        nb=nb+abs(word.index(str(a[0]))-(int((len(word)+1)/2)-1))
    return nb
word=input()
c=nb(word)
print(c)
        
