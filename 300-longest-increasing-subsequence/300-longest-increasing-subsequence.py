class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        arr = []
        for i in range(len(nums)):
            if not arr:
                arr.append(nums[i])
            else:
                if arr[-1] < nums[i]:
                    arr.append(nums[i])
                else:
                    idx = bisect.bisect_left(arr, nums[i])
                    arr[idx] = nums[i]
        return len(arr)
        