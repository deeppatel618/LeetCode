class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr = sorted(arr)
        arr_ = [abs(arr[i+1] - arr[i]) for i in range(len(arr)-1)]
        min_diff = min(arr_)
        arr_new = []

        for i in range(len(arr)-1):
            if (abs(arr[i+1] - arr[i]) == min_diff):
                arr_new.append([arr[i],arr[i+1]])

        return arr_new