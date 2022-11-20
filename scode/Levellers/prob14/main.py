s=input()
List=s.split(" ")

if(s[0].isalpha() or s[1].isalpha()):
    print("INPUT_ERROR")
else:
    T_size=input()
    T_number=input()
    if(T_size.isalpha() or T_number.isalpha()):
        print("INPUT_ERROR")
    else :
       if (int(T_number)==0) : print(0)
       elif((int(T_number)*int(T_size)) < int(List[0]) and (int(T_number)*int(T_size)<int(List[1]))):
               print(int(T_number)*int(T_size))
       else:
          sizeTable=(int(T_number)*int(T_size))
          if((sizeTable-int(List[0]))>4 and (sizeTable-int(List[1]))>4):
              print(sizeTable-int(T_size))
          else: 
              print(sizeTable-max(sizeTable-int(List[0]),(sizeTable-int(List[1])))+1) 