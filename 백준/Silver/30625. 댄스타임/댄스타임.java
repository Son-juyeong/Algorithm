import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1_000_000_007L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long m = Long.parseLong(st.nextToken());

        int[] dir = new int[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            dir[i] = Integer.parseInt(st.nextToken());
        }

        long ans = m % MOD;

        long cnt;
        if (dir[0] == 0) cnt = 1;
        else cnt = (m - 1) % MOD;

        for (int i = 1; i < n; i++) {
            if (dir[i] == 1) {
                ans = (ans * ((m - 1) % MOD) + cnt) % MOD;
                cnt = (cnt * ((m - 1) % MOD)) % MOD;
            } else {
                ans = (ans + cnt * ((m - 1) % MOD)) % MOD;
            }
        }

        System.out.println(ans);
    }
}
