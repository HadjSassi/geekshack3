line1 = input()
line2 = input()

num_titans = int(line1.split(" ")[0])
num_special = int(line1.split(" ")[1])
titans_lealth = line2.split(" ")

titans_lealth = [eval(i) for i in titans_lealth]

done = False
for i in range(num_special):
  try:
    titans_lealth.remove(max(titans_lealth))
  except:
    print("0")
    done = True
if not done:
  print(sum(titans_lealth))
