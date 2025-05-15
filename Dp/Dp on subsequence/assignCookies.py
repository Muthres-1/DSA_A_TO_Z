class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()
        s.sort()
        n = len(g)
        m = len(s)
        child = 0
        cookie = 0

        while child < n and cookie < m:
            if g[child] <= s[cookie]:
                child += 1  # Move to the next child
            cookie += 1  # Always move to the next cookie

        return child  # Number of content children
