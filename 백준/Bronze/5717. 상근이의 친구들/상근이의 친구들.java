import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int f = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();

        while(!(m==0&&f==0)){
            sb.append(m + f).append("\n");
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            f = Integer.parseInt(st.nextToken());
        }
        System.out.println(sb);
    }
}