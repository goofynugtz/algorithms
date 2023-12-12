def solution(l, t):
  n = len(l)
  for i in range(n):
    summation = 0
    for j in range(i, n):
      summation += l[j]
      if summation == t:
        return [i, j]
  return [-1, -1]


if __name__ == "__main__":
  print(solution([4, 3, 10, 2, 8], 12))
  print(solution([4, 3, 5, 7, 8], 12))