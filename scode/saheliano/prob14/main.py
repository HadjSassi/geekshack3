def isPalindrome(s):
    return s == s[::-1]
  


def isUniqueChars(st):
 
    # String length cannot be more than
    # 256.
    if len(st) > 256:
        return False
 
    # Initialize occurrences of all characters
    char_set = [False] * 128
 
    # For every character, check if it exists
    # in char_set
    for i in range(0, len(st)):
 
        # Find ASCII value and check if it
        # exists in set.
        val = ord(st[i])
        if char_set[val]:
            return False
 
        char_set[val] = True
 
    return True
  
  
def allFrequencies(input:str) -> dict:
  all_freq = {}
  for i in input:
    if i in all_freq:
        all_freq[i] += 1
    else:
        all_freq[i] = 1
  return all_freq



def canFormPalindrome(st):
    NO_OF_CHARS = 256
    # Create a count array and initialize
    # all values as 0
    count = [0] * (NO_OF_CHARS)
 
    # For each character in input strings,
    # increment count in the corresponding
    # count array
    for i in range(0, len(st)):
        count[ord(st[i])] = count[ord(st[i])] + 1
 
    # Count odd occurring characters
    odd = 0
 
    for i in range(0, NO_OF_CHARS):
        if (count[i] & 1):
            odd = odd + 1
 
        if (odd > 1):
            return False
 
    # Return true if odd count is 0 or 1,
    return True
  
# one odd count character


# return the sequence of chars that has odd occ
def getListCharWithOddOcc(input:dict) -> str:
  res = [d for d in input if input[d]%2 != 0]
  return input[res[0]] * res[0]


def convertStrToList(input:str)-> list:
  lst = []
  for i in input:
    lst.append(i)
  return lst

swap_count = 0


# check whether the oddChars are cetnerd in the input
def isCentered(input:str,oddChar:str, oddCharCount:int) :
  start_indx = int((len(input) - oddCharCount) / 2)
  end_indx = int(start_indx + oddCharCount -1)
  char = input[start_indx]
  if char != oddChar:
    return False
  for i in range(start_indx+1, end_indx+1):
    if input[i] != char:
      return False
  return True


def swap(input:list, i:int, j:int)->list:
  temp = input[i]
  input[i] = input[j]
  input[j] = temp
  return input


def swap_extreme(input:list, remaining_range) -> int:
  temp_count = 0
  temp = input.copy() # save a copy
     
  # first range only
  working_lst = temp.copy()
  for i in range(remaining_range - 1):
    input = swap(working_lst, i, i+1)
    temp_count += 1
    if isPalindrome(input):
      return temp_count

  # last range only
  temp_count = 0
  working_lst = temp.copy()
  for i in range(len(input) - remaining_range -1):
    input = swap(working_lst, i, i+1)
    temp_count += 1
    if isPalindrome(input):
      return temp_count
    
  # both ranges
  # temp_count = 0
  # working_lst = temp.copy()
  
  # for i in range(remaining_range - 1):
  #   input = swap(working_lst, i, i+1)
  #   temp_count += 1
  #   for i in range(len(input) - remaining_range -1):
  #     input = swap(working_lst, i, i+1)
  #     temp_count += 1
  #     if isPalindrome(input):
  #       return temp_count
  
# there's always, if existed, only 1 char with odd frequency "aabab"
def numberSwappOneOdd(input):
  global swap_count
  ## get the list of the characters with odd freq
  allFreqDict = allFrequencies(input)
  oddChars = getListCharWithOddOcc(allFreqDict)
  
  ## Swapp until we put these characters in the middle
  temp = convertStrToList(input)
  i = 0
  while(not isCentered(temp, oddChars[0], len(oddChars))):
    temp = swap(temp, i, i+1)
    swap_count += 1
    i += 1
    if i == len(temp)-1:
      i = 0
  ## check if palindrome
  if (isPalindrome(temp)):
    return swap_count
  ## Swapp the other (extreme) characters (all possiblities) until we get a palindrome
  remaining_range = (len(temp) - len(oddChars)) / 2 # remaining chars
  temp_swap_count = swap_extreme(temp, remaining_range)
  return temp_swap_count + swap_count
  ## return -1
  
input1 = input()
if (not canFormPalindrome(input1)):
  print("-1")
else:
  print(str(numberSwappOneOdd(input1)))