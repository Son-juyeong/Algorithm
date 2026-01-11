import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st.nextToken();
        for (int i = 0; i < n; i++) {
            br.readLine();
        }
        System.out.println("비와이");
    }
}