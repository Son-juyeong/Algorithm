import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int r;
        int c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    static char[][] arr;
    static boolean[][] visited;
    static int[] dr = {0, 1, 0, -1};
    static int[] dc = {1, 0, -1, 0};
    static int N;
    static int M;

    public static int power(int r, int c, char team) {
        int result = 1;
        visited[r][c] = true;
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(r, c));
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int newR = cur.r + dr[i];
                int newC = cur.c + dc[i];
                if (newR >= 0 && newR < M && newC >= 0 && newC < N && arr[newR][newC] == team && !visited[newR][newC]) {
                    ++result;
                    visited[newR][newC] = true;
                    q.offer(new Node(newR, newC));
                }
            }
        }
        return result * result;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new char[M][N];
        visited = new boolean[M][N];

        for (int i = 0; i < M; i++) {
            String str = br.readLine();
            for (int j = 0; j < N; j++) {
                arr[i][j] = str.charAt(j);
            }
        }

        int W = 0, B = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    char team = arr[i][j];
                    int temp = power(i, j, team);
                    if (team == 'W')
                        W += temp;
                    else B += temp;
                }
            }
        }

        System.out.println(W + " " + B);
    }
}