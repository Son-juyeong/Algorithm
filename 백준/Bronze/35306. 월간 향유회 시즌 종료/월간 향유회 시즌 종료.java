import java.io.*;
import java.util.*;

//월간 향유회... 문제: 월간 향유회 시즌 종료... 이거 지우지마.......ㅠㅠㅠㅠ
public class Main {

    static class Person implements Comparable<Person> {
        int idx;
        int score;

        public Person(int idx, int score) {
            this.idx = idx;
            this.score = score;
        }

        @Override
        public int compareTo(Person o) {
            return o.score - this.score;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Queue<Person>[] pq = new Queue[K];
        for (int i = 0; i < K; i++) {
            pq[i] = new PriorityQueue<>();
        }

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < K; j++) {
                int score = Integer.parseInt(st.nextToken());
                pq[j].offer(new Person(i, score));
            }
        }

        Set<Integer> p = new HashSet<>();

        for (int i = 0; i < K; i++) {
            Person p1 = pq[i].poll();
            if (pq[i].isEmpty()) {
                p.add(p1.idx);
                break;
            }
            Person p2 = pq[i].poll();
            if (p1.score != p2.score) {
                p.add(p1.idx);
            }
        }

        System.out.println(p.size());
    }
}