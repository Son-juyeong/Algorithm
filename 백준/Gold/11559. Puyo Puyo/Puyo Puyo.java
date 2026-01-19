import java.io.*;
import java.util.*;

public class Main {

    static char[][] puyo;
    static int[] dr = {1, 0, 0, -1};
    static int[] dc = {0, 1, -1, 0};

    static class Node {
        int r;
        int c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static List<Node> getPopping(int row, int col, char ch, boolean[][] visited) {
        List<Node> result = new ArrayList<>();
        Queue<Node> q = new ArrayDeque<>();
        visited[row][col] = true;
        result.add(new Node(row, col));
        q.offer(new Node(row, col));
        while (!q.isEmpty()) {
            Node cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int r = cur.r + dr[i];
                int c = cur.c + dc[i];
                if (r >= 0 && r < 12 && c >= 0 && c < 6 && !visited[r][c] && puyo[r][c] == ch) {
                    visited[r][c] = true;
                    result.add(new Node(r, c));
                    q.offer(new Node(r, c));
                }
            }
        }
        return result;
    }

    public static void renewal(List<Node> list) {
        for (Node cur : list) {
            puyo[cur.r][cur.c] = '.';
        }
        for (int c = 0; c < 6; c++) {
            int write = 11;

            for (int r = 11; r >= 0; r--) {
                if (puyo[r][c] != '.') {
                    puyo[write][c] = puyo[r][c];
                    if (write != r) puyo[r][c] = '.';
                    write--;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        puyo = new char[12][6];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 12; i++) {
            String str = br.readLine();
            for (int j = 0; j < 6; j++) {
                puyo[i][j] = str.charAt(j);
            }
        }

        int answer = 0;

        while (true) {
            boolean isPop = false;
            boolean[][] visited = new boolean[12][6];
            List<Node> list = new ArrayList<>();
            for (int i = 11; i >= 0; i--) {
                for (int j = 0; j < 6; j++) {
                    if (!visited[i][j] && puyo[i][j] != '.') {
                        List<Node> temp = getPopping(i, j, puyo[i][j], visited);
                        if (temp.size() >= 4) {
                            isPop = true;
                            list.addAll(temp);
                        }
                    }
                }
            }
            if (!isPop) break;
            ++answer;
            renewal(list);
        }
        System.out.println(answer);
    }
}
