class Solution:
    def strStr(self,  haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        lps = [0] * len(needle)
        prevLPS, i = 0, 1
        ans = []
        while i < len(needle):
            if needle[i] == needle[prevLPS]:
                lps[i] = prevLPS + 1
                prevLPS += 1
                i += 1
            elif prevLPS == 0:
                lps[i] = 0
                i += 1
            else:
                prevLPS = lps[prevLPS - 1]
        i = 0
        j = 0
        while (i < len(haystack)):
            if (haystack[i] == needle[j]):
                i, j = i + 1, j + 1
            else:
                if j == 0:
                   i += 1
                else:
                    j = lps[j - 1]

            if j == len(needle):
                ans.append(i - j)
                j = lps[j - 1]

        return ans
# s = Solution()
# text = "ABABABABAAABABAABABBABAAABABABABBABABABABBABABABABABABABABABABABABAAAAABABABBBBABBABABABA"
# pat = "ABA"
# b = s.strStr(text, pat)
# print(b)
# for num in b:
#     print(text[num : len(pat) + num], end = " ")
