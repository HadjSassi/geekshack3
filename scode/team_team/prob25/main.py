# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    return int(data)

n = get_number()
li = []
for _ in range(n):
    li.append(get_number())


# 初始化树状数组
# fw数组对应的原数组含义是
# 考虑前面元素进行交换后，对后续元素交换带来的影响
# 前后元素的下标之差 - 1后，由于之前有过交换步骤，所以可能会带来步骤的减少
fw = [0] * (n + 1)

# 树状数组的标准操作函数
# get_sum(end)：计算从数组开始到end位置的前缀和
# rans(start, end)：计算从start到end位置的区间和
# upd(ind)：在ind位置更新树状数组的值
def get_sum(end):
	res = 0
	while(end > 0):
		res += fw[end]
		end = end & (end - 1)
	return res

def rans(start, end):
	return get_sum(end+1) - get_sum(start)

def upd(ind):
	while(ind < n+1):
		fw[ind] += 1
		ind = ind + (ind & -ind)

# 遍历数组，记录每个数字的位置
# mp类似于 - {7: [0, 4], 3: [1, 3], 5: [2, 6], 6: [5, 7]}
from collections import defaultdict
mp = defaultdict(list)
for i in range(len(li)):
	mp[li[i]].append(i)

# 计算交换次数
ans = 0
for num in li:
    # 若数字已经被匹配过，则不考虑了
	if num not in mp.keys():
		continue
	# 拿到当前数字的匹配对，并删除
	start, end, *rest = mp[num]
	del mp[num]
	if rest:
	    mp[num] = rest
	# 计算首位两个位置的区间和
	curr = rans(start, end)
	# 更新树状数组值
	upd(end + 1)
	# 交换次数累加
	ans += end - start - 1 - curr
	
print(ans)
