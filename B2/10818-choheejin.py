# cook your dish here
import sys

list = []
N = sys.stdin.readline()
input = sys.stdin.readline().split()

for i in input:
  list.append(int(i))

result = sorted(list)
cnt = len(result) - 1
print(result[0], result[cnt])
