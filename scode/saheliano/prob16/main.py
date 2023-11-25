first_line = input()
num_cities = int(first_line.split(" ")[0])
num_roads = int(first_line.split(" ")[1])
capital = int(first_line.split(" ")[2])


# inputting roads
roads = []
distance = [[0]*(num_cities+1)]*(num_cities+1)

for i in range(num_roads):
  line = input().split(" ")
  roads.append((int(line[0]), int(line[1]), int(line[2]))) # (1, 2, 1) => (city1, city2, distance)
  distance[int(line[0])][int(line[1])] = int(line[2])

l = int(input()) # distance from the capital to the launchers


# find the connected cities along with their distance [(node, dist), (...), ...]
def find_aretes(node:int) -> list:
  aretes = []
  for road in roads:
    if road[0] == node:
      aretes.append((road[1], road[2]))
    elif road[1] == node:
      aretes.append((road[0], road[2]))
  return aretes
  
# create the graph of the cities    
cities_graph = {}
for i in range(1, num_cities+1):
  aretes = find_aretes(i)
  cities_graph[i] = aretes
  

def unique(list1):
    # initialize a null list
    unique_list = []
    # traverse for all elements
    for x in list1:
        # check if exists in unique_list or not
        if x not in unique_list:
            unique_list.append(x)
    return unique_list

# return the list of adjacent nodes of the given node, excluding the given [(node, dist), (node, dist), ...]
def adjacent_nodes(node:int) -> list:
  return cities_graph[node]


count = 0

# check if there's a laucnher starting from the start_node to the adj_node
def there_is_launcher(start_node:int, adj_nodes:list, remaining_dist=l)->int:
  global count
  if remaining_dist <= 0:
    # stop condition, one road found
    count += 1
    return
  for node in adj_nodes:
    if (isinstance(start_node, tuple)):
      if (remaining_dist - distance[start_node[0]][node[0]]) <= 0 :
        count += 1 # one road found
      else:
        return there_is_launcher(node, adjacent_nodes(node[0]), remaining_dist - distance[start_node[0]][node[0]])
    else:
      if (remaining_dist - distance[start_node][node[0]]) <= 0 :
        count += 1 # one road found
      else:
        return there_is_launcher(node, adjacent_nodes(node[0]), remaining_dist - distance[start_node][node[0]])

there_is_launcher(capital, adjacent_nodes(capital), l)
print(int(count))