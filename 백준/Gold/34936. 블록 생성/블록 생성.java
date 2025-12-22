import java.io.*;
import java.util.*;

public class Main {

    static class Transaction implements Comparable<Transaction> {
        int t;
        int cost;

        public Transaction(int t, int cost) {
            this.t = t;
            this.cost = cost;
        }

        @Override
        public int compareTo(Transaction o) {
            if (this.cost == o.cost)
                return this.t - o.t;
            return o.cost - this.cost;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Queue<Transaction> pq = new PriorityQueue<>();

        long answer = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int type =Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            switch (type){
                case 1:
                    int f = Integer.parseInt(st.nextToken());
                    pq.offer(new Transaction(t, f));
                    break;
                case 2:
                    int cnt = 0;
                    while(!pq.isEmpty()&&cnt<K){
                        Transaction cur = pq.poll();
                        if(t-cur.t<=T){
                            answer += cur.cost;
                            ++cnt;
                        }
                    }
                    break;
            }
        }

        System.out.println(answer);
    }
}
