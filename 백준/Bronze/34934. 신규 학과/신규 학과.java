import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String answer = new String();

        for(int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String major = st.nextToken();
            int year = Integer.parseInt(st.nextToken());
            if(year==2026)
                answer = major;
        }

        System.out.println(answer);
    }
}