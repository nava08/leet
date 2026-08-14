class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        freq = {}
        left = 0
        max_len = 0
        
        for right in range(len(s)):
            char = s[right]
            freq[char] = freq.get(char, 0) + 1
            
            # Shrink the window until the current character's count is at most 2
            while freq[char] > 2:
                freq[s[left]] -= 1
                left += 1
            
            # Update the maximum valid window length found so far
            max_len = max(max_len, right - left + 1)
            
        return max_len