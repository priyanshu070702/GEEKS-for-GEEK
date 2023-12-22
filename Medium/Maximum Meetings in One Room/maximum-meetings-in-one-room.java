//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int N; 
            N = Integer.parseInt(br.readLine());
            
            
            int[] S = IntArray.input(br, N);
            
            
            int[] F = IntArray.input(br, N);
            
            Solution obj = new Solution();
            ArrayList<Integer> res = obj.maxMeetings(N, S, F);
            
            IntArray.print(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static ArrayList<Integer> maxMeetings(int N, int[] S, int[] F) {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        int[][] meeting = new int[N][3];
        for(int i=0; i<N; i++){
            meeting[i][0] = i;
            meeting[i][1] = S[i];
            meeting[i][2] = F[i];
        }
        Arrays.sort(meeting, Comparator.comparingDouble(o -> o[2]));
        list.add(meeting[0][0]+1);
        int lastEndTime = meeting[0][2];
        for(int i=1; i<N; i++){
            if(meeting[i][1] > lastEndTime){
                list.add(meeting[i][0]+1);
                lastEndTime = meeting[i][2];
            }
        }
        Collections.sort(list);
        return list;
    }
}
        
