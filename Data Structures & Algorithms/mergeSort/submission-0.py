# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def mergeSort(self, pairs: List[Pair]) -> List[Pair]:
        return self.helperFunc(pairs , 0 , len(pairs) - 1)

    def helperFunc(self , pairs: List[Pair] , s: int , e: int) -> List[Pair]:
        if e - s + 1 <= 1:
            return pairs
        m = (e + s)//2
        self.helperFunc(pairs , s , m)
        self.helperFunc(pairs , m+1 , e)
        self.merger(pairs , s , m, e)
        return pairs
    

    def merger(self , pairs: List[Pair] , s: int , m: int , e: int)->None:
        left = pairs[s:m+1]
        right = pairs[m+1:e+1]
        i = 0
        j = 0
        k = s

        while i < len(left) and j < len(right):
            if left[i].key <= right[j].key:
                pairs[k] = left[i]
                i += 1
            else:
                pairs[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            pairs[k] = left[i]
            i+=1
            k+=1
        while j < len(right):
            pairs[k] = right[j]
            j+=1
            k+=1
        








