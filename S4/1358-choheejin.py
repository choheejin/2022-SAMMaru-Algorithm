import sys
import math


def in_circle(x, y, X, Y, r):
  sum = (X - x)**2 + (Y - y)**2
  if math.sqrt(sum) <= r:
    return True
  else:
    return False
  
W, H, X, Y, P = map(int, sys.stdin.readline().split())
R = H/2
result = 0

for _ in range(0, P, 1):
  x, y = map(int, sys.stdin.readline().split())
  if y <= Y+H and y >= Y: # y좌표 안 인지 확인
    if x > X and x < X+W : # 사각형 안 인지 확인
      result += 1
    else:
      if(x <= X and x >= X - R): # 왼쪽 동그라미
        if(in_circle(x, y, X, Y+R, R) == True):
          result += 1
      if(x >= X+W and x <= X+W + R): # 오른쪽 동그라미
        if(in_circle(x, y, X+W, Y+R, R) ==True):
          result += 1

print(result)
