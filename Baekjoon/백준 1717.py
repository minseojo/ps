import sys

n, m = map(int, sys.stdin.readline().split())
arr = [i for i in range(n+1)]

def get_parent(n):
    if arr[n] != n:
        arr[n] = get_parent(arr[n])
    return arr[n]

def union_(u, v):
    u = get_parent(u)
    v = get_parent(v)
    if u > v:
        arr[v] = u
    else:
        arr[u] = v

# 또 다른 맞은 함수
def union_(u, v):
    u = get_parent(u)
    v = get_parent(v)
    if u != v:
        arr[v]=u
    else:
        return arr[u]

# 또 다른 틀린 함수 (이유 모름)
def union_(u, v):
    u = get_parent(u)
    v = get_parent(v)
    if u < v:
        arr[v] = u
    else:
        arr[u] = v
def find_parent(u, v):
    u = get_parent(u)
    v = get_parent(v)
    if u == v:
        print("YES")
    else:
        print("NO")

for _ in range(m):
    r, a, b = map(int, sys.stdin.readline().split())
    if not r:
        union_(a, b)
    else:
        a = get_parent(a)
        b = get_parent(b)
        if a==b:
            print("YES")
        else:
            print("NO")
