N,K=map(int,input().split())
List = list(map(int, input().split()))
 
def imosu(x,k):
  data = [0]*k
  for i in range(k):
    first = i-x[i]
    last = i+x[i]
    if first < 0:
      first = 0
    data[first] += 1
    if last+1 < k:
      data[last+1] +=-1
  ruiseki = [0]*k
  ruiseki[0] = data[0]
  for i in range(k-1):
    ruiseki[i+1] = ruiseki[i] + data[i+1]
  return ruiseki
 
for i in range(K):
  List = imosu(List,N)
  if List.count(N) == N:
    break
print(*List)
