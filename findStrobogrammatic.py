class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        #["11","69","88","96"]
        # 1 8 0 
        # 0 1 8 6 9
        # 1 8 69 
        # 1001 1111 1691 1881 1961
        if n == 1:
            return ["0", "1", "8"]
        if n == 2:
            return ["11", "69", "88", "96"]
        
        baseDigits = {
            '0': '0',
            '1': '1',
            '6': '9',
            '8': '8',
            '9': '6'
        }
        def helper(n: int) -> List[str]:
            if n == 1:
                return ["0", "1", "8"]
            if n == 2:
                return ["00", "11", "69", "88", "96"]
            res = []
            for digit in baseDigits:
                for sbnum in helper(n - 2):
                    res.append(digit + sbnum + baseDigits[digit])
            
            return res
        
        res = []
        for digit in baseDigits:
            if digit == '0':
                continue
            for sbnum in helper(n - 2):
                res.append(digit + sbnum + baseDigits[digit])
        return res