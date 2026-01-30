import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int max = 0;
        int num = 0;
        String answer = "";

        for(int i = 0;i<n;i++){
            String name = br.readLine();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int cnt = 0;
            while(m/k>0){
                int temp = m / k;
                m %= k;
                m += temp * 2;
                cnt += temp;
            }
            if(cnt>max){
                max = cnt;
                answer = name;
            }
            num += cnt;
        }

        System.out.println(num);
        System.out.println(answer);
    }
}
