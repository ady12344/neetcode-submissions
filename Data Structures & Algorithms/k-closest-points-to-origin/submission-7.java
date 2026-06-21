class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] result = new int[k][2];
        helper(points , 0 , points.length - 1 , k);
        for(int i = 0 ; i < k ; i++){
            result[i] = points[i];
        }
        return result;
    }
    public void helper(int[][] points, int start, int end , int k){
        if(end - start + 1 <= 1) return;
        int[] pivot = points[end];
        int pivotDist = (int)(Math.pow(pivot[0] , 2) + Math.pow(pivot[1] , 2));
        int left = start;
        for(int i = start ; i < end ; i++){
            int[] point = points[i];
            int pointDist = (int)(Math.pow(point[0] , 2) + Math.pow(point[1] , 2));
            if(pivotDist > pointDist){
                int[] temp = point;
                points[i] = points[left];
                points[left] = temp;
                left++;
            }
        }
        points[end] = points[left];
        points[left] = pivot;
        //helper(points , start, left - 1);
        //helper(points , left + 1 , end);
         if (left == k) {
            return;                                    // first k elements are the closest
         } else if (left > k) {
            helper(points, start, left - 1, k);
         } else {
            helper(points, left + 1,end, k);
        }
    }
}
