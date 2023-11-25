s = input()
Rook = [s[2],s[1]]
s = input()
BKing = [s[2],s[1]]
s = input()
WKing = [s[2],s[1]]


if Rook[0] == WKing[0] or Rook[1] == WKing[1]:
    if Rook[0] == WKing[0] and BKing[0] == WKing[0]:
        if WKing[1] < BKing[1] < Rook[1] or Rook[1] < BKing[1] < WKing[1]:
            print("NO")
    elif Rook[1] == WKing[1] and BKing[1] == WKing[1]:
        if WKing[0] < BKing[0] < Rook[0] or Rook[0] < BKing[0] < WKing[0]:
            print("NO")

else:
    print("YES")