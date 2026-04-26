class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
    	int total = k1 + k2;
    	PriorityQueue<Integer> maxheap = new PriorityQueue<>((a, b) -> b - a);
    	Map<Integer, Integer> map = new HashMap<>();
    	for (int i = 0; i < nums1.length; i++) {
    		int diff = Math.abs(nums1[i] - nums2[i]);
    		map.put(diff, map.getOrDefault(diff, 0) + 1);
    	}
    	for (int k : map.keySet()) {
    		if (k == 0) continue;
    		maxheap.add(k);
    	}
    	while (total > 0 && !maxheap.isEmpty()) {
    		int cur = maxheap.poll();
    		int d = Math.min(total, map.get(cur));
    		map.put(cur, map.get(cur) - d);
    		if (map.get(cur) > 0) maxheap.add(cur);
    		int next = cur - 1;
            if (next > 0) {
                map.put(next, map.getOrDefault(next, 0) + d);
    		    if (map.get(next) == d) maxheap.add(next);
            }
    		total -= d;
    	}
    	long res = 0;
    	while (!maxheap.isEmpty()) {
    		int cur = maxheap.poll();
    		res = res + (long)cur * cur * map.get(cur);
    	}
    	return res;
    }
}