n, b = input().split()
b = int(b)
answer = 0
arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

for i in range(len(n)):
    answer += arr.find(n[len(n)-i-1])*(b**i)
print(answer)

# 다른 답안
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

# 최고 답안
n, b= input().split()
print(int(n, int(b)))
