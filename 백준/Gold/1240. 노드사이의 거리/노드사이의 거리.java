import java.io.*;
import java.util.*;

public class Main {
    static int[][] arr = new int[1001][1001];
    static int[][] answer = new int[1001][1001];
    static boolean[][] visited = new boolean[1001][1001];
    static void dfs(int r, int dis, int n, int start, int end){
        if(r==end)
            return;
        for(int i = 1;i<=n;i++){
            if(arr[r][i]!=-1&&!visited[r][i]){
                visited[r][i]=true;
                visited[i][r]=true;
                dfs(i, dis+arr[r][i], n, start, end);
                answer[start][i]=dis+arr[r][i];
                answer[i][start]=dis+arr[r][i];
                visited[r][i]=false;
                visited[i][r]=false;
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                arr[i][j]=-1;
            }
        }
        for(int i = 0;i<n-1;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            arr[a][b]=c;
            arr[b][a]=c;
        }
        for(int i = 0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            dfs(a, 0, n, a, b);
            sb.append(answer[a][b]+"\n");
        }
        System.out.println(sb);
    }
}