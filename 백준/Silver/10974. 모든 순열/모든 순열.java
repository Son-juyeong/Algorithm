import java.io.*;
import java.util.*;

public class Main {

    static int n;

    public static void dfs(int depth, int[] arr, boolean[] visited){
        if(depth==n){
            for(int i = 0;i<n;i++){
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            return;
        }
        for(int i = 1; i<=n;i++){
            if(!visited[i]){
                visited[i]=true;
                arr[depth]=i;
                dfs(depth + 1, arr, visited);
                visited[i]=false;
            }

        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dfs(0, new int[n], new boolean[n+1]);
    }
}