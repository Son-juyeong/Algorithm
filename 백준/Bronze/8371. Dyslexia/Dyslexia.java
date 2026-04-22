import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String str1 = br.readLine();
        String str2 = br.readLine();
        int answer = 0;
        for(int i=0;i<N;i++){
            char c1 = str1.charAt(i);
            char c2 = str2.charAt(i);
            if(c1!=c2){
                ++answer;
            }
        }
        System.out.println(answer);
    }
}