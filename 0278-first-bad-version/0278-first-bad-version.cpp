// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    int left = 1, right = n;
        
        while (left < right) {
            // Prevent integer overflow when calculating mid
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                // mid is bad, so first bad version is at mid or earlier
                right = mid;
            } else {
                // mid is good, so first bad version is after mid
                left = mid + 1;
            }
        }
        
        return left; // or right, they are equal here
    }
};