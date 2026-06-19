class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ctr1 = Counter(s);
        ctr2 = Counter(t);
        return ctr1 == ctr2;

        