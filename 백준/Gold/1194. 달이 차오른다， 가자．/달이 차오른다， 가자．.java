import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int r;
        int c;
        int d;
        int k;

        public Node(int r, int c, int d, int k) {
            this.r = r;
            this.c = c;
            this.d = d;
            this.k = k;
        }
    }

    static int N, M;
    static char[][] arr;
    static boolean[][][] visited;

    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, 1, 0, -1};

	public static int bfs(int row, int col){
		Queue<Node> q = new ArrayDeque<>();
		q.offer(new Node(row, col, 0, 0));

		while (!q.isEmpty()) {
			Node cur = q.poll();
			for(int i = 0;i<4;i++){
				int r = cur.r+dr[i];
				int c = cur.c+dc[i];
				int d = cur.d+1;
				if(r>=0&&r<N&&c>=0&&c<M&&arr[r][c]!='#'){
					if(visited[r][c][cur.k]) continue;

					if('a'<=arr[r][c]&&arr[r][c]<='f'){
						int k = cur.k|(1<<(arr[r][c]-'a'));
						visited[r][c][k]=true;
						q.offer(new Node(r, c, d, k));
					}
					else if('A'<=arr[r][c]&&arr[r][c]<='F'){
						if((cur.k&(1<<(arr[r][c]-'A')))==1<<(arr[r][c]-'A')){
							visited[r][c][cur.k]=true;
							q.offer(new Node(r, c, d, cur.k));
						}
					}
					else if(arr[r][c]=='.'){
						visited[r][c][cur.k]=true;
						q.offer(new Node(r, c, d, cur.k));
					}
					else if(arr[r][c]=='1'){
						return d;
					}
				}
			}
		}

		return -1;
	}

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new char[N][M];
        visited = new boolean[N][M][64];

        int sr = -1, sc = -1;

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                arr[i][j] = str.charAt(j);
                if (arr[i][j] == '0') {
                    sr = i;
                    sc = j;
                    arr[i][j] = '.';
                }
            }
        }

		System.out.println(bfs(sr, sc));

    }
}