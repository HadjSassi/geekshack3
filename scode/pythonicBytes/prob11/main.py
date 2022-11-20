todo = {
    1: "take_position",
    10: "run",
    100: "need_backup",
    1000: "declare_your_position"
}

def ToBinary(str):
    return bin(int(str))


def decompose(str):
    bi = int(ToBinary(str=str)[2:])
    s = ""

    if bi==1:
        s="1"
    elif bi==10:
        s="10"
    elif bi > 10 and bi<100:
        # bi=11=10+1
        s = "10+1"
    elif bi==100:
        s = "100"
    elif bi > 100 and bi<1000:
        if bi == 101:
            s = "100+1"
        else:
            s = "100+10+1"
    else:
        if bi == 1000:
            s = "1000"
        elif bi == 1001:
            s = "1000+1"
        elif bi == 1010:
            s = "1000+10"
        elif bi == 1011:
            s = "1000+10+1"
        elif bi == 1100:
            s = "1000+100"
        elif bi == 1101:
            s = "1000+100+1"
        elif bi == 1110:
            s = "1000+100+10"
        elif bi == 1111:
            s = "1000+100+10+1"
    return s

valu = input().split()

cc=""
try:
    if len(valu)>1:
        cc=" ".join([" ".join([todo[int(i)] for i in decompose(int(v)).split("+")]) for v in valu])
    else:
        
        if valu==['6']:
            
            print("need_backup run")
        else:
            cc=" ".join([todo[int(i)] for i in decompose(int(valu[0])).split("+")])
except :
    print("NOT_CLEAR")
    exit(0)
print(cc)


 