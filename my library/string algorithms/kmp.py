class Solution:
    def strStr(self,  haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        lps = [0] * len(needle)
        prevLPS, i = 0, 1
        # prevLPSlist = []
        # iList = []
        while i < len(needle):
            # prevLPSlist.append(prevLPS)
            # iList.append(i)
            if needle[i] == needle[prevLPS]:
                lps[i] = prevLPS + 1
                prevLPS += 1
                i += 1
            elif prevLPS == 0:
                lps[i] = 0
                i += 1
            else:
                prevLPS = lps[prevLPS - 1]

        # print("prevLPSList : ", prevLPSlist)
        # print("iList :       ", iList)

        i = 0
        j = 0
        # print("LPSList :     ", lps("AABAACAABAAA"))
        while (i < len(haystack)):
            if (haystack[i] == needle[j]):
                i, j = i + 1, j + 1
            else:
                if j == 0:
                   i += 1
                else:
                    j = lps[j - 1]

            if j == len(needle):
                return i - j

        return -1

s = Solution()
print(s.strStr("AABAACAABAAA", "BAAA"))
