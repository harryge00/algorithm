class Solution:
    def shortestWordDistance(self, words: List[str], word1: str, word2: str) -> int:
        i, j = 0, 0
        n = len(words)
        # x,x,a,x,x,x,a,x,x,b,x,b,x,x,x,a,x,x,b
        # x,x,a,x,x,x,a,x,x,b,x,b,x,x,x,a,x,x,b,x
        res = n
        while i < n and j < n:
            while i < n:
                if words[i] == word1 and j != i:
                    if words[j] == word2: 
                        # j = 0 is the start index
                        res = min(res, abs(i - j))
                    if i > j:
                        break
                i += 1

            while j < n:
                if words[j] == word2 and j != i:
                    res = min(res, abs(i - j))
                    if j > i:
                        break
                j += 1
                

            
        return res

