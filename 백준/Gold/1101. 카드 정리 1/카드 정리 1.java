import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int answer = 0;
        boolean[] hasCard = new boolean[M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < M; j++) {
                int t = Integer.parseInt(st.nextToken());
                if (t > 0) list.add(j);
            }
            if (list.size() > 1) {
                ++answer;
            } else if (list.size() == 1) {
                if (hasCard[list.get(0)]) {
                    ++answer;
                } else hasCard[list.get(0)] = true;
            }
        }

        System.out.println(Math.max(--answer, 0));
    }
}