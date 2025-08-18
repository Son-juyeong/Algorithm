import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for(int tc=1;tc<=10;tc++){
            sb.append("#").append(tc).append(" ");
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<String> list = new LinkedList<>();
            for(int i = 0;i<N;i++){
                String str = st.nextToken();
                list.add(str);
            }
            int M = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            for(int i = 0;i<M;i++){
                String cmd = st.nextToken();
                if(cmd.equals("I")){
                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());
                    for(int j = x;j<x+y;j++){
                        String s = st.nextToken();
                        list.add(j, s);
                    }
                }
                else if(cmd.equals("D")){
                    int x = Integer.parseInt(st.nextToken());
                    int y = Integer.parseInt(st.nextToken());
                    for(int j = 0;j<y;j++){
                        list.remove(x);
                    }
                }
                else if(cmd.equals("A")){
                    int y = Integer.parseInt(st.nextToken());
                    for(int j = 0;j<y;j++){
                        String s = st.nextToken();
                        list.add(s);
                    }
                }
            }
            for(int i = 0;i<10;i++){
                sb.append(list.get(i)).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
}