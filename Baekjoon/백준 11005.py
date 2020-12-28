n, b = map(int, input().split())
answer = ''

while n != 0:
    if n%b >= 10:
        answer+= chr(55+n%b)
    else:
        answer+=str(n%b)
    n//=b
    
print(answer[::-1])

#다른 답안
n, b = map(int, input().split())
answer = ''

while n > 0:
  temp = n % b
  n //= b

  if temp >= 10:
    temp = chr(temp + 55)
  else:
    temp = str(temp)
  answer = temp + answer

print(answer)
