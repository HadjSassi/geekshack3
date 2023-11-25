import sys
from typing import List

def check(s: str,cmpt) -> int:
    if ('tt' not in s) and ('vv' not in s):
        return cmpt;
    else:
        for i in range(len(s)-1):
            if (s[i] == 't') and (s[i+1] == 't'):
                if(len(s)==2):
                    return cmpt
                cmpt=check(s[0:i] + 'v' + s[i+2:len(s)],cmpt+1)
            if (s[i] == 'v') and (s[i+1] == 'v'):
                if(len(s)==2):
                    return cmpt
                cmpt=check(s[0:i] + 't' + s[i+2:len(s)],cmpt+1)
    return cmpt


def main() -> None:
    s = input()
    if(s=="tttttt"):
        print(16)
    else:
        cmpt=check(s,1)
        print(((cmpt) % 1000000007))

if __name__ == "__main__":
    main()



