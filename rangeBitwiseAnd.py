class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        if checkSameBits(m, n) == False:
            return 0
        # 25 31
        # 11001
        k = n - m
        i = 1
        while k != 0:
            k >>= 1
            i <<= 1
        
        return m & i

    def checkSameBits(m, n) -> bool:
        while m != 0 :
            m >>= 1
            n >>= 1
        return n == 0