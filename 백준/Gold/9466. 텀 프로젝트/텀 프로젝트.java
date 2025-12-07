import java.io.*;
import java.util.*;

public class Main {

    static boolean[] visited;
    static int[] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int tc = 1; tc <= T; tc++) {
            int n = Integer.parseInt(br.readLine());
            visited = new boolean[n + 1];
            arr = new int[n + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            int answer = 0;

            for (int i = 1; i <= n; i++) {
                if (arr[i] == i) continue;
                if (!visited[i]) {
                    List<Integer> list = new ArrayList<>();
                    visited[i] = true;
                    list.add(i);
                    int t = arr[i];
                    while(true){
                        if(visited[t]){
                            if(list.contains(t)){
                                int idx = list.indexOf(t);
                                answer += idx;
                            }else{
                                answer+=list.size();
                            }
                            break;
                        }else{
                            if(t==arr[t]){
                                answer += list.size();
                                break;
                            }
                            list.add(t);
                            visited[t]=true;
                            t = arr[t];
                        }
                    }
                }
            }

            sb.append(answer).append("\n");
        }

        System.out.println(sb);
    }
}