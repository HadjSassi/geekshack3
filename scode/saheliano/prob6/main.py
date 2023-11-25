n = int(input())
line = input()
operation = line.split(" ")[0]
sentence = line.split(" ")[1]



def get_divisors(n):
    for i in range(1, int(n / 2) + 1):
        if n % i == 0:
            yield i
    yield n

list_divisors = list(get_divisors(n))


# encryption
if operation == 'E':
  list_divisors.reverse()
  for divisor in list_divisors:
    first_half = sentence[:divisor]
    second_half = sentence[divisor:]
    first_half = first_half[::-1]
    sentence = first_half + second_half


if operation == 'D':
  for divisor in list_divisors:
    first_half = sentence[:divisor]
    second_half = sentence[divisor:]
    first_half = first_half[::-1]
    sentence = first_half + second_half

print(sentence)


