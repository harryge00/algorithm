def insert(stones, num):
    res = []
    for i in range(stones):
        if num <= stones[i]:
            # 新石头找插入位置
            res[i] = num
            res.extend(stones[i:])
            return res
        else:
            res[i] = stones[i]

    res.append(num)
    return res

def lastStoneWeight(stones):
    stones.sort()
    n = len(stones)
    while n > 1:
        stones = insert(stones[0:n - 2], stones[n - 1] - stones[n - 2])
        n -= 1
    
    return stones[0]

    

