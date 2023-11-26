from collections import defaultdict

def main():


	n = int(input())

	arr = [int(x) for x in input().split(" ")]


	fw_size = n+1

	def get_sum(start):
		result = 0
		while(start > 0):
			result += fw[start]
			start = start&(start-1)


		return result



	def range_sum(start, end):
		return get_sum(end+1) - get_sum(start)


	def update(index):
		val = 1
		while(index < fw_size):
			fw[index] += val
			index = index + (index & -index)



	fw = [0]*(fw_size)

	mp = defaultdict(list)

	for i in range(len(arr)):
		mp[arr[i]].append(i)

	result = 0

	# print(val_arr)

	# print(range_sum(0, 7))
	# print(range_sum(3, 6))
	
	for num in arr:

		if num not in mp.keys():
			continue
		start, end, *rest = mp[num]
		del mp[num]
		curr = range_sum(start, end)

		update(end + 1)
		result += (end-start-1-curr)

	return result

print(main())