n, b = input().split()
b = int(b)
answer, cnt = 0, 0

for i in n[::-1]:
    if i.isdigit():
        target = int(i)
    else:
        target = ord(i) - 55
    answer += target * (b**cnt)
    cnt+=1
print(answer)
