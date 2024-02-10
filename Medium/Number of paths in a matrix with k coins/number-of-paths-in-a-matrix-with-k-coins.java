//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            
            int  k = Integer.parseInt(read.readLine());
            int  n = Integer.parseInt(read.readLine());
            int arr[][] = new int[n][n];
            String input_line1[] = read.readLine().trim().split("\\s+");
            int c = 0;
            for(int i=0;i<n;i++){
                for(int j = 0;j<n;j++){
                    arr[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            Solution obj = new Solution();
            System.out.println(obj.numberOfPath(n, k, arr));
        }
    }
}

// } Driver Code Ends


//User function Template for Java

    class Solution {
    long find(int n,int k,int[][] arr,int x,int y){
        if(x>=n || y>=n || k<0) return 0;
        if(x==n-1 && y==n-1 && k-arr[x][y]==0) return 1; 
        long a=find(n,k-arr[x][y],arr,x+1,y);
        long b=find(n,k-arr[x][y],arr,x,y+1);
        return a+b;
    }
    long numberOfPath(int n, int k, int [][]arr) {
        return find(n,k,arr,0,0);
    }
}