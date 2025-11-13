import java.io.*;
import java.util.*;

public class Main {

    static class Node{
        int r;
        int c;
        int dis;
        public Node(int r, int c, int dis){
            this.r = r;
            this.c = c;
            this.dis = dis;
        }
    }

    static int[] dr = {0, 1, 1, 1, 0, -1, -1, -1};
    static int[] dc = {1, 1, 0, -1, -1, -1, 0, 1};

    static int n, m;

    static int[][] arr;

    public static int bfs(int r, int c){
        Queue<Node> q = new ArrayDeque<Node>();
        boolean[][] visited = new boolean[n][m];
        visited[r][c]=true;
        q.offer(new Node(r, c, 0));

        while(!q.isEmpty()){
            Node cur = q.poll();
            for(int i = 0;i<8;i++){
                int newR = cur.r + dr[i];
                int newC = cur.c + dc[i];
                int newDis = cur.dis+1;
                if(newR>=0&&newR<n&&newC>=0&&newC<m&&!visited[newR][newC]){
                    if(arr[newR][newC]==1)
                        return newDis;
                    visited[newR][newC]=true;
                    q.offer(new Node(newR, newC, newDis));
                }
            }
        }
        return 0;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n][m];

        for(int i = 0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0;j<m;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int answer = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j]==0){
                    answer = Math.max(answer, bfs(i, j));
                }
            }
        }

        System.out.println(answer);
    }
}