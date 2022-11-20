a = input()
l = a.split(" ")
ch1 = ""
t = True
l1 = ["take_position", "run", "need_backup", "declare_your_position"]

for i in l:
    if (i.isnumeric()):
        continue
    else:
        print("NOT_CLEAR")
        t = False
        break
if t:

    for i in l:
        ch = bin(int(i))
        ch = ch[2:]
        n = int(ch)
        for j in range(len(ch) - 1, -1, -1):
            if n // 10 ** j==1:
                ch1 += l1[j] + " "
                n=n% 10** j
print(ch1.strip(" "))
