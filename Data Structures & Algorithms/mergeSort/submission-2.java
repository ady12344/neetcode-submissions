// Definition for a pair.
// class Pair {
//     public int key;
//     public String value;
//
//     public Pair(int key, String value) {
//         this.key = key;
//         this.value = value;
//     }
// }
class Solution {
    public List<Pair> mergeSort(List<Pair> pairs) {
        return mergeHelper(pairs, 0 , pairs.size() - 1);
    }

    public List<Pair> mergeHelper(List<Pair> pairs , int s, int e){
        if(e - s + 1 <= 1) return pairs;
        int middle = (s+e)/2;
        mergeHelper(pairs , s , middle);
        mergeHelper(pairs , middle+1 , e);

        merge(pairs , s ,middle ,e);  

        return pairs;
    }
    public void merge(List<Pair> pairs, int start , int middle, int end){
        Pair[] left = new Pair[middle - start + 1];
        Pair[] right = new Pair[end - middle];
        for(int i = 0 ; i < left.length ; i++){
            left[i] = pairs.get(i + start);
        }
        for(int i = 0 ; i < right.length ; i++){
            right[i] = pairs.get(i + middle + 1);
        }
        int k = start;
        int i = 0;
        int j = 0;
        while(i < left.length && j < right.length){
            if(left[i].key <= right[j].key){
                pairs.set(k,left[i]);
                i++;
            }else{
                pairs.set(k,right[j]);
                j++;
            }
            k++;
        }

        while(i < left.length){
            pairs.set(k,left[i]);
            k++;
            i++;
        }
        while(j < right.length){
            pairs.set(k, right[j]);
            k++;
            j++;
        }

    }
}
