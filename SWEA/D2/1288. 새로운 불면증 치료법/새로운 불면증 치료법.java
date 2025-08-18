import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;tc++){
            sb.append("#").append(tc).append(" ");
            int N = Integer.parseInt(br.readLine());
            int answer = N;
            int bit = 0;
            while(bit!=((1<<10)-1)){
               String str = Integer.toString(answer);
               for(int i = 0;i<str.length();i++){
                   int temp = str.charAt(i)-'0';
                   bit|=(1<<(temp));
               }
                answer+=N;
            }
            sb.append(answer-N).append("\n");
        }
        System.out.println(sb);
    }
}