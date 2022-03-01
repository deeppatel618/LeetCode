class Solution:
    def countBits(self, n: int) -> List[int]:
        if n==0:
            return [0]
        elif n==1:
            return [0,1]
        x=[0,1]
        j=0
        le=2
        for i in range(2,n+1):
            if le==j:
                j=0
                le=len(x)
            x.append(x[j]+1)
            j+=1
        return x