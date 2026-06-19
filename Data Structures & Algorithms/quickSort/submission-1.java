// Definition for a pair.
// class Pair {
//     int key;
//     String value;
//
//     public Pair(int key, String value) {
//         this.key = key;
//         this.value = value;
//     }
// }
class Solution {
    public List<Pair> quickSort(List<Pair> pairs) {
        //aight we cooking
        quickSortHelper(pairs , 0 , pairs.size() - 1);
        return pairs;
    }
    public void quickSortHelper(List<Pair> pairs , int start, int end){
        if(end - start + 1 <= 1) return;
        Pair pivot = pairs.get(end);
        int leftPtr = start;
        for(int i = start; i < end ; i++){
            if(pivot.key > pairs.get(i).key){
                Pair temp = pairs.get(leftPtr);
                pairs.set(leftPtr, pairs.get(i));
                pairs.set(i , temp);
                leftPtr++;
            }
        }
        pairs.set(end , pairs.get(leftPtr));
        pairs.set(leftPtr, pivot);
        quickSortHelper(pairs , start , leftPtr - 1);
        quickSortHelper(pairs, leftPtr+1 , end);
        
    }
}
