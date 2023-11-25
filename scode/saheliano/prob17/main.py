text = input()
count = 0
record = []
set_all = set()

def possible_opeartion(c1, c2):
  return c1 == c2

def execute_op(tx:str, i, j):
  first = tx[:i]
  if (j == len(tx)-1):
    if tx[i] == "v":
      return first + "t"
    else:
      return first + "v"
  else:
    last = tx[j+1:]
    if tx[i] == "v":
      first += "t"
    else:
      first += "v"
  return first + last


def search_possibilites(txt):
  global record
  global count
  global set_all
  #print(txt)
  for i in range(len(txt)-1):
    if possible_opeartion(txt[i], txt[i+1]):
      res = execute_op(txt, i, i+1)
      count += 1
      set_all.add(res)
      record.append(res) if res not in record else record


search_possibilites(text) # init


while record:
  elt = record[0]
  search_possibilites(elt)
  record = record[1:]
  
if count == 0:
  print("1")
else:
  print(str(len(set_all)+1) )


