pos_black_rook=input()
pos_black_king=input()
pos_white_king=input()
def check(pos_black_king,pos_white_king):
    if((abs(int(pos_black_king[2])-int(pos_white_king[2])==2)or(abs(ord(pos_black_king[1])-ord(pos_white_king[1]))==2))):
        return True
    return False
def solve(pos_black_rook,pos_black_king,pos_white_king):
    if((abs(int(pos_black_rook[2])-int(pos_white_king[2]))==1)or(abs(ord(pos_black_rook[1])-ord(pos_white_king[1]))==1)) and (check(pos_black_king,pos_white_king)) and ((pos_white_king[1]==pos_black_king[1])and (pos_black_king[1]==pos_black_rook[1])):
        print("NO")
    else:
        print("YES")
solve(pos_black_rook,pos_black_king,pos_white_king)
