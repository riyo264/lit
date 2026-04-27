class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int [] leftSum = new int [n];
        int [] rightSum = new int [n];
        int [] leftCnt = new int[n];
        int [] rightCnt = new int[n];
        int [] ans = new int[n];

        leftSum[0] = 0;
        leftCnt[0] = 0;
        for(int i = 0; i < n-1; i++) {
            if(boxes.charAt(i) == '1') {
                leftSum[i+1] = (leftSum[i] + i);
                leftCnt[i+1] = (leftCnt[i] + 1);
            }
            else {
                leftSum[i+1] = leftSum[i];
                leftCnt[i+1] = leftCnt[i];
            }
        }

        rightSum[0] = 0;
        rightCnt[0] = 0;
        for(int i = n-1; i > 0; i--) {
            if(boxes.charAt(i) == '1') {
                rightSum[i-1] = (rightSum[i] + i);
                rightCnt[i-1] = (rightCnt[i] + 1);
            }
            else {
                rightSum[i-1] = rightSum[i];
                rightCnt[i-1] = rightCnt[i];
            }
        }

        for(int i = 0; i < n; i++) {
            ans[i] += (i*leftCnt[i] - leftSum[i]);
            ans[i] += (rightSum[i] - (i*rightCnt[i]));
        }

        return ans;
    }
}