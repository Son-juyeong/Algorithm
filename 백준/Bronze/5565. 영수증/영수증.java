import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int answer = Integer.parseInt(br.readLine());
        for(int i=0;i<9;i++){
            answer-=Integer.parseInt(br.readLine());
        }
       System.out.println(answer);
    }
}