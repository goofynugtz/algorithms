import copy
def knapsack(lst, idx, sm, st, btmsk, dp):
    if idx==-1:
        if sm%3==0:
            st.append(btmsk)
            return 1
        return 0

    if dp[idx][btmsk]!=-1:
        return dp[idx][btmsk]

    flag = knapsack(lst, idx-1, sm+lst[idx], st, btmsk|(1<<idx), dp)
    flag = flag | knapsack(lst, idx-1, sm, st, btmsk, dp)
    dp[idx][btmsk]=flag
    return dp[idx][btmsk]
        

def solution(nums):
    mp = dict()
    for i in range(0,10):
        mp[i]=0


    for x in nums:
        if x not in mp:
            mp[x]=1
        else:
            mp[x]+=1

    dct = dict()

    for i in range(0,10):
        if i%3==0:
            continue
        dct[i]=0
        for x in range(0, (mp[i]//3)):
            dct[i]+=3

        mp[i]=mp[i]%3

    lst = []
    for i in range(9,0,-1):
        if i%3==0:
            continue
        for x in range(0, mp[i]):
            lst.append(i)
    st = []
    dp = []
    for i in range(0, lst.__len__()+1):
        temp = []
        for j in range(0, 4097):
            temp.append(-1)
        dp.append(temp)

    btmsk = 0
    sm = 0
    knapsack(lst, lst.__len__()-1,sm,st,btmsk, dp)

    st = sorted(st, key=lambda x:bin(x).count('1'), reverse=True)
    st = [x for x in st if bin(x).count('1')==bin(st[0]).count('1')]


    
    for i in range(0, 10):
        if i%3==0:
            continue
        mp[i]=0
        if i in dct:
            mp[i]=dct[i]
    num = ""
    for i in range(9,-1,-1):
        for x in range(0, mp[i]):
            num+=str(i)

    value = ""
    # print(num)
    for x in st:
        y = copy.deepcopy(num)
        for i in range(0,lst.__len__()):
            if((1<<i)&x)!=0:
                y+=str(lst[i])

        y = sorted(y, reverse=True)
        string=""
        for z in y:
            string+=z
        if value=="":
            value=string
        else:
            value = max(value, string)
    
    return value

print(solution([3,4,1,1]))
