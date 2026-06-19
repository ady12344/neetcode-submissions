class Solution:
    def climbStairs(self, n: int) -> int:
        return self.helperFunc(n , 0)
    def helperFunc(self , n: int, i: int) -> int:
        if i >= n:
            if i == n : return 1
            else : return 0
        return self.helperFunc(n , i+1) + self.helperFunc(n , i+2)
    
    
        