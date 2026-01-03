import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int t = 0;t<T;t++){
            int N = Integer.parseInt(br.readLine());
            int odd = 0, even = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0;i<N;i++){
                int temp = Integer.parseInt(st.nextToken());
                if(temp%2==0){
                    ++even;
                }else ++odd;
            }
            if(odd%2==0&&even%2==0){
                sb.append("heeda0528\n");
            }else if(odd%2!=0&&even%2!=0){
                if(odd==even){
                    sb.append("heeda0528\n");
                }else
                    sb.append("amsminn\n");
            }else if(odd%2!=0&&odd>even||even%2!=0&&odd<even){
                sb.append("amsminn\n");
            }else{
                sb.append("heeda0528\n");
            }
        }
        System.out.println(sb);
    }
}