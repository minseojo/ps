n = int(input(), 2) # n을 2진수로 입력 받음
n = oct(n) # n을 8진수로 바꿈
print(n[2:]) #8진수로 바꾸면 0o로 시작 => 2번째 인덱스부터 출력

# 다른 답안
n = input()
cnt, sums = 0, 0
answer = ''
l = len(n)
for i in range(l):
    if cnt==3:
       answer =str(sums) + answer
       cnt=0
       sums=0
    sums += 2**cnt*int(n[l-i-1])
    cnt+=1
print(str(sums)+answer)
