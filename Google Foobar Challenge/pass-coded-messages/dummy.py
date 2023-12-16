def check(lst, s, index, sum):
  if index >= len(lst):
    if sum % 3:
      return ""
    else:
      ret = s[0:]
      return ret
  s1 = check(lst, s, index + 1, sum)
  s2 = check(lst, s + chr(lst[index] + 48), index + 1, sum+lst[index])
  if len(s1) < len(s2):
    return s2
  elif len(s1) == len(s2):
    f = True
    for i in range(0, len(s1)):
      if s1[i] > s2[i]:
        f = False
        break
    if f:
      return s1
    return s2
  return s1


def solution(l):
  l.sort(reverse=True)
  s = check(l, "", 0, 0)
  if s=="":
    return "0"
  return s


print(solution([3, 1, 4, 1, 5, 9]))
