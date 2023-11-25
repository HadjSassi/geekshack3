s = input()
count=0
while(s.find("chak") != -1):
    s = s[s.find("chak") + 4::]

    l = s

    while(l.find("chouka") != -1):
        l = l[:l.find("chouka")] + l[l.find("chouka") + 6::]

        count += 1
print(count)