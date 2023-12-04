#User function Template for python3
class Solution:
    def isSumString(self, input_string):
        string_length = len(input_string)

        def is_valid_sum(i, j, k):
            nonlocal input_string, string_length

            if k == string_length:
                return True
            if k > string_length:
                return False

            num1 = int(input_string[i:j])
            num2 = int(input_string[j:k])
            sum_str = str(num1 + num2)

            if not input_string[k:].startswith(sum_str):
                return False

            return is_valid_sum(j, k, k + len(sum_str))

        for i in range(1, string_length):
            for j in range(i + 1, string_length):
                if is_valid_sum(0, i, j):
                    return 1

        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=str(input())

        ob = Solution()
        
        print(ob.isSumString(S))
# } Driver Code Ends