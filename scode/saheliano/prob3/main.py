len_chak = 10
txt = input()
len_txt = len(txt)
count = 0

if (len_txt < len_chak):
  print("-1")




def check_chackhouka(input:str)->bool:
  chack = input[:4]
  chouka = input[4:]
  return chack == "chak" and chouka == "chouka"

if (len_txt == len_chak):
  if check_chackhouka(txt):
    print("1")

for i in range(len_txt):
  #print('i=', i)
  if i + len_chak <= len_txt:
    chak = txt[i:i+4]
    if chak != "chak":
      continue
    # looking for chouka
    end = len_txt
    for j in range((len_txt - 4) - i):
      chouka = txt[len_txt-6-j:len_txt-j]
      if chouka == "chouka":
        #print("chouka=", chouka)
        count +=1
  else:
    break
print(count)
  
#print(check_chackhouka("chakcdhouka"))