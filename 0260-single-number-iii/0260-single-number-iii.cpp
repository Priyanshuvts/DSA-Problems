class Solution{	
public:		
	vector<int> singleNumber(vector<int>& nums){
		int ab = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            ab ^= nums[i];
        }
        int x = ab;
        int sb = 0;
        while(x){
            if(x & 1) break;
            x = x >> 1;
            sb ++;
        }
        int a = 0;
        int b = 0;
        for(int i = 0; i < n; i ++){
            if(nums[i] & (1 << sb)) a ^= nums[i];
            else b ^= nums[i];
        }
        return {b , a};
	}
};