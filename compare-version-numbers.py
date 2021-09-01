class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        flag = 1
        if len(v1) < len(v2):
            v1, v2 = v2, v1
            flag = - 1
        for i in range(len(v2)):
            if int(v1[i]) > int(v2[i]):
                return flag
            elif int(v1[i]) < int(v2[i]):
                return - flag
        for i in range(len(v2), len(v1)):
            if int(v1[i]) > 0:
                return flag
        return 0