import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int x, y;

        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        Node[] list = new Node[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            list[i] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(list, (a, b) -> {
            if (a.x == b.x) {
                return a.y - b.y;
            } else {
                return a.x - b.x;
            }
        });

        for (Node now : list) {
            bw.write(now.x + " " + now.y + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}