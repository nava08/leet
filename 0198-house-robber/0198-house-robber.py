class Solution:
    def rob(self, nums: List[int]) -> int:
        prev2 = 0  # Represents max profit up to i-2
        prev1 = 0  # Represents max profit up to i-1

        for num in nums:
            # Decide whether to rob the current house or skip it
            current = max(prev2 + num, prev1)
            
            # Shift variables forward for the next iteration
            prev2 = prev1
            prev1 = current

        return prev1