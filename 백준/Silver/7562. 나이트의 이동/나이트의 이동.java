import java.io.*;
import java.util.*;

public class Main {

    static int[] dr = {-2, -1, 1, 2, 2, 1, -1, -2};
    static int[] dc = {1, 2, 2, 1, -1, -2, -2, -1};

    static class Node{
        int r;
        int c;
        int cnt;
        public Node(int r, int c, int cnt) {
            this.r=r;
            this.c=c;
            this.cnt=cnt;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int tc = 0;tc<t;tc++){
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int sr = Integer.parseInt(st.nextToken());
            int sc = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int er = Integer.parseInt(st.nextToken());
            int ec = Integer.parseInt(st.nextToken());
            boolean[][] visited = new boolean[n][n];

            Queue<Node> q = new ArrayDeque<>();

            q.offer(new Node(sr, sc, 0));
            visited[sr][sc]=true;
            int answer = 0;
            if(sr==er&&sc==ec){
                sb.append(answer).append("\n");
                continue;
            }

            while(!q.isEmpty()){
                Node cur = q.poll();
                boolean isFinish = false;
                for(int i = 0;i<8;i++){
                    int r = cur.r + dr[i];
                    int c = cur.c + dc[i];
                    int cnt = cur.cnt+1;

                    if(r>=0&&r<n&&c>=0&&c<n&&!visited[r][c]){
                        if(r==er&&c==ec){
                            answer=cnt;
                            isFinish=true;
                            break;
                        }
                        visited[r][c]=true;
                        q.offer(new Node(r, c, cnt));
                    }
                }
                if(isFinish) break;
            }
            sb.append(answer).append("\n");
        }
        System.out.println(sb);
    }

}