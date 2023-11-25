def estPalind(ch):
    if len(ch) == 0 or len(ch) == 1:
        return 1
    if ch[0] == ch[-1]:
        return estPalind(ch[1:len(ch) - 1])
    return 0


ch = input()

j = 0
palind = 1
while j < len(ch) and palind:

    if estPalind(ch):
        print(str(j))
        palind = 0
    else:
        ch = ch[1:] + ch[0]
        j += 1
if not (estPalind(ch)):
    print(-1)