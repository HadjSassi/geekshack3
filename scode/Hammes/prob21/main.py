ch=input().split(" ")
n=int(ch[0])
for i in range(0,n):
    ch1=input()
# Assume the prices of painting each house in a specific color is
# given by an array of size 3xN, giving the price to paint each house
# for each specific color
def find_cheap_house_painters(N, prices):
    # initialize the totals array
    totals = [[0 for i in range(N)] for j in range(3)]

    # the first houses are special case
    # we just paint them, that's it.
    for color in range(3):
        totals[color][0] = prices[color][0]

    # after that, dynamic programming does its magic.
    # at each step, add the price of painting this house
    # to the minimum of the total painting of the other two colors
    colors = set(range(3))
    for house in range(1, N):
        for color in colors:
            previous_totals = [totals[other_color][house-1] for other_color in (colors - {color})]
            totals[color][house] = prices[color][house] + min(previous_totals)

    # so now we have the totals to paint up to each house
    # we'll just work backwards to find the coloring of the houses.
    colorings = [3 for i in range(N)]
    colorings[-1] = min(colors, key=lambda x : totals[x][-1])
    for house in range(N-2, -1, -1):
        # take the index of the smaller option
        other_colors = colors - {colorings[house+1]}
        colorings[house] = min(other_colors, key=lambda x : totals[x][house])

    # convert to a human-readable string
    color_names = "RGB"
    house_colorings = "".join([color_names[colorings[house]] for house in range(N)])
    return house_colorings 
print(find_cheap_house_painters(2,[[7,5,8,4,6,9,3,7,4,8],[5,8,4,6,7,3,9,4,8,6]]))