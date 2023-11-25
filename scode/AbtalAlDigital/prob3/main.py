s=input();
delicious_count = 0

for i in range(len(s)):
    if s[i:i+4] == "chak":  
        for j in range(i+4, len(s)):
            if s[j:j+6] == "chouka": 
                delicious_count += 1

print(delicious_count);



