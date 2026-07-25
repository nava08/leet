#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(std::vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            // If the lightest and heaviest person can share a boat
            if (people[left] + people[right] <= limit) {
                left++;
            }
            // Heaviest person always takes a boat (alone or shared)
            right--;
            boats++;
        }
        
        return boats;
    }
};