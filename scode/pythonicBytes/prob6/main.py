class Prof:
    def __init__(self, name, dur, profit):
        self.name = name
        self.dur = dur
        self.profit = profit

    def __repr__(self) -> str:
        return f'{self.name} {self.dur} {self.profit}'

    def get_items(self):
        return [self.name, int(self.dur), int(self.profit)]
_hours = int(input(""))  # hours number
_inpt = int(input(""))  # profits number

_mett = []
while _inpt > 0:
    name, dur, profit=input().split()
    _mett.append(Prof(name, dur, profit))
    _inpt -= 1
z=sorted([i.get_items() for i in _mett], key=lambda ele: ele[1]) # sorted by duration
first=z[0]

rest=_hours-int(first[1])
z=z[1:]
z=list(filter(lambda s: s[1]<=rest,z)) # filter 

z=sorted(z, key=lambda ele: ele[2],reverse=True)

second=z[0]

_names,profits=first[0]+" "+second[0],int(first[2])+int(second[2])
print(_names)
print(profits)
 