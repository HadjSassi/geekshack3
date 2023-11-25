def generate_all_possible_strings(s):
    chaines_possibles = set()
    chaines_possibles.add(s)

    while True:
        combinaisons = set()
        for y in chaines_possibles:
            tt = [i for i in range(len(y) - 1) if y[i:i + 2] == 'tt']
            vv = [i for i in range(len(y) - 1) if y[i:i + 2] == 'vv']

            for t in tt:
                comb = y[:t] + 'v' + y[t + 2:]
                combinaisons.add(comb)

            for t in vv:
                comb = y[:t] + 't' + y[t + 2:]
                combinaisons.add(comb)

        combinaisons -= chaines_possibles
        if not combinaisons:
            break
        chaines_possibles |= combinaisons
    return len(chaines_possibles)%1000000007
s = input()
print(generate_all_possible_strings(s))