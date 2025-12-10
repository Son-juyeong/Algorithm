import java.io.*;
import java.util.*;

public class Main {

    static int[][] palindrome;
    static int[] arr;

    public static int isPalindrome(int start, int end){
        while(start<=end){
            if(arr[start]!=arr[end])
                return 0;
            ++start;
            --end;
        }
        return 1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        palindrome = new int[n + 1][n + 1];
        arr = new int[n + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1;i<=n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1;i<=n;i++){
            for(int j = i;j<=n;j++){
                palindrome[i][j] = isPalindrome(i, j);
            }
        }

        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            sb.append(palindrome[start][end]).append("\n");
        }

        System.out.println(sb);
    }
}