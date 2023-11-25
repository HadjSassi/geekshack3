def read_inputs():
    line1 = int(input())
    stacks = []
    for i in range(line1):
        stacks.append(list(map(lambda x: int(x), input().split()[1:])))
    return stacks
def stacks_not_empty(stacks):
    test = False
    for i in range(len(stacks)):
        test = test or stack_not_empty(stacks[i])
    return test
def stack_not_empty(stack):
    return len(stack) > 0

def min_len_stacks_id(stacks):
    filtered_list = list(filter(lambda x: len(x)!=0, stacks))

    return stacks.index(min(filtered_list, key=lambda x: len(x)))

def player1_played(stacks: list):
    index_min = min_len_stacks_id(stacks)
    stack = stacks[index_min]
    sc = stack.pop(0)
    return stacks, sc

def player2_played(stacks: list):
    index_min = min_len_stacks_id(stacks)
    stack = stacks[index_min]

    sc = stack.pop(-1)
    return stacks, sc

if __name__ == '__main__':
    stacks = read_inputs()
    player1 =0
    player2 =0
    while stacks_not_empty(stacks):
        stacks, sc = player1_played(stacks)
        player1 += sc
        if stacks_not_empty(stacks) :
            stacks, sc = player2_played(stacks)
            player2 += sc

    print(f'{player1} {player2}')