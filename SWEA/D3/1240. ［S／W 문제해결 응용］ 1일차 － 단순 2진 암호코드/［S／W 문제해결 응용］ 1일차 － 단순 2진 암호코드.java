import java.io.*;
import java.util.*;

public class Solution {

    static Map<String, Integer> map = new HashMap<String, Integer>(){{
       put("0001101", 0);
       put("0011001", 1);
       put("0010011", 2);
       put("0111101", 3);
       put("0100011", 4);
       put("0110001", 5);
       put("0101111", 6);
       put("0111011", 7);
       put("0110111", 8);
       put("0001011", 9);
    }};

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;tc++){
            sb.append("#").append(tc).append(" ");
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int answer = -1;
            for(int i = 0;i<N;i++){
                String str = br.readLine();
                if(answer!=-1) continue;
                for(int j=M-1;j>=0;j--){
                    if(str.charAt(j)=='1'){
                        answer = 0;
                        int idx = j-55;
                        int temp = 0;
                        for(int k = 1;k<=8;k++){
                            int t = map.get(str.substring(idx, idx+7));
                            idx+=7;
                            if(k%2==1)
                                temp+=t*3;
                            else temp+=t;
                            answer+=t;
                        }
                        if(temp%10!=0)
                            answer = 0;
                        break;
                    }
                }
            }
            sb.append(answer).append("\n");
        }
        System.out.println(sb);
    }
}