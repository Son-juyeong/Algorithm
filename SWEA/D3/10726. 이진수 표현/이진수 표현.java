import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;tc++){
            sb.append("#").append(tc).append(" ");

            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            int bit = (1<<N)-1;
            sb.append((M&bit)==bit?"ON":"OFF").append("\n");
        }
        System.out.println(sb);
    }
}