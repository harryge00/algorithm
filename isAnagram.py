class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        m = {}
        for c in s:
            if c not in m:
                m[c] = 1
            else:
                m[c] += 1

        for c in t:
            if c not in m or m[c] == 0:
                return False
            else:
                m[c] -= 1
        
        return True
