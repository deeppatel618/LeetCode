class Solution:
    def subsets(self, ls: List[int]) -> List[List[int]]:
        ans=[[]]
        for i in range(len(ls)):
            if len(ans)!=(len(ls)**2)-1:
                length=len(ans)
                temp=[]
                for j in range(length):
                    temp=ans[j].copy()
                    temp.append(ls[i])
                    ans.append(temp)
        return ans