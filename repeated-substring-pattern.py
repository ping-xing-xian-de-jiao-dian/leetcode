class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        leng = len(s)
        if leng == 1:
            return False
        for i in range(1, int(leng / 2) + 1):
            if (leng % i == 0):
                string = s[:i:]
                res = ""
                for j in range(int(leng / i)):
                    res += string
                    if res != s[:i * (j + 1):]:
                        break
                else:
                    return True
        return False