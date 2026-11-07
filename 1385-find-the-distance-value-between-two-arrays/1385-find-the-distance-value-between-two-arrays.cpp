class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int count = 0;

        for (int x : arr1) {
            int low = 0;
            int high = arr2.size() - 1;
            bool found = false;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr2[mid] >= x - d && arr2[mid] <= x + d) {
                    found = true;
                    break;
                }
                else if (arr2[mid] < x - d) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            if (!found) {
                count++;
            }
        }
        return count;
    }
};