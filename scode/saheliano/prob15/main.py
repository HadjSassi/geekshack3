interval = input()
count = 0


x = int(interval.split(" ")[0])
y = int(interval.split(" ")[1])

def get_binary_repr(input:int):
  list1 = []
  while (input > 0):
    list1.append(str(input % 2))
    input = input//2
  return "".join(list1)

def allFrequencies(input:str) -> dict:
  all_freq = {}
  for i in input:
    if i in all_freq:
        all_freq[i] += 1
    else:
        all_freq[i] = 1
  return all_freq

def contains_only_one_0(input:str) -> bool:
  all_freq = allFrequencies(input)
  try:
    if all_freq['0'] == 1:
      return True
  except:
    return False
  return False

for i in range(x, y+1):
  binary = get_binary_repr(i)
  if contains_only_one_0(binary):
    count += 1
  
print(count) 