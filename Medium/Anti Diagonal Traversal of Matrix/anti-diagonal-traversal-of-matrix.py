#User function Template for python3

class Solution:
    def antiDiagonalPattern(self,matrix):
        ar=[]
        key=0
        n=len(matrix)
        for i in range((n-1)*2+1):
            for i in range(n):
                for j in range(n):
                    if i + j == key:
                        ar.append(matrix[i][j])
            key+=1
        return ar


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input()) 
        inp=list(map(int,input().split()))
        matrix=[]
        k = 0
        for i in range(n):
            row = []
            for j in range(n):
                row.append(inp[k])
                k += 1
            matrix.append(row)
        ob = Solution()
        ans = ob.antiDiagonalPattern(matrix)
        for i in ans:
            print(i,end=" ")
        print()


# } Driver Code Ends