import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node>{
        int r;
        int c;
        int cnt;

        public Node(int r, int c, int cnt){
            this.r=r;
            this.c=c;
            this.cnt=cnt;
        }

        @Override
        public int compareTo(Node o) {
            return this.cnt-o.cnt;
        }
    }

    public static void dfs(int idx){
        if(idx==zero.size()){
            for(int i = 0;i<9;i++){
                for(int j = 0;j<9;j++){
                    System.out.print(sudoku[i][j]);
                }
                System.out.println();
            }
            isSuccess=true;
            return;
        }
        if(isSuccess) return;
        Node cur = zero.get(idx);
        for(int i = 1;i<=9;i++){
            int key = 1 << (i - 1);
            if((row[cur.r]&key)!=0||(col[cur.c]&key)!=0||(block[(cur.r / 3) * 3 + (cur.c / 3)]&key)!=0) continue;
            row[cur.r] |= key;
            col[cur.c] |= key;
            block[(cur.r / 3) * 3 + (cur.c / 3)] |= key;
            sudoku[cur.r][cur.c] = i;
            dfs(idx + 1);
            row[cur.r] ^= key;
            col[cur.c] ^= key;
            block[(cur.r / 3) * 3 + (cur.c / 3)] ^= key;
            sudoku[cur.r][cur.c] = 0;
        }
    }

    static int[][] sudoku = new int[9][9];
    static int[] row = new int[9];
    static int[] col = new int[9];
    static int[] block = new int[9];
    static List<Node> zero;
    static boolean isSuccess = false;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        zero = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            String str = br.readLine();
            for (int j = 0; j < 9; j++) {
                sudoku[i][j] = str.charAt(j) - '0';
                if (sudoku[i][j] > 0) {
                    int key = (1 << (sudoku[i][j] - 1));
                    row[i] |= key;
                    col[j] |= key;
                    block[(i / 3) * 3 + (j / 3)] |= key;
                }
                else{
                    zero.add(new Node(i, j, 0));
                }
            }
        }

        for(int i = 0;i< zero.size();i++){
            Node cur = zero.get(i);
            int cnt = 0;
            for(int j=1;j<=9;j++){
                if((row[cur.r]&j)==0&&(col[cur.c]&j)==0&&(block[(cur.r / 3) * 3 + (cur.c / 3)]&j)==0)
                    ++cnt;
            }
            cur.cnt=cnt;
        }

//        Collections.sort(zero);
        dfs(0);
    }
}