# def r(i, numbers, row, ds):
#   if (i >= len(numbers)):
#     return
  
#   row.append(numbers[i])
#   t1 = tuple(row)
#   ds.add(t1)
#   r(i+1, numbers, row, ds)
  
#   row.pop()
#   t2 = tuple(row)
#   ds.add(t2)
#   r(i+1, numbers, row, ds)


def solution(L):


# Test Cases
print(solution([3,1,4,1]))
print(solution([3, 1, 4, 1, 5, 9]))