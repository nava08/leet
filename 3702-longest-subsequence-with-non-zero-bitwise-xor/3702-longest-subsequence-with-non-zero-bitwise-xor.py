class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        total_xor = 0
        all_zero = True
        
        for num in nums:
            total_xor ^= num
            if num != 0:
                all_zero = False
        
        # If all elements are 0, every subsequence XORs to 0
        if all_zero:
            return 0
        
        # If total XOR is already non-zero, we can pick all elements
        if total_xor != 0:
            return len(nums)
        
        # If total XOR is 0 but non-zero elements exist, removing any non-zero element gives non-zero XOR
        return len(nums) - 1