import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] bear = new int[3];
        for(int i =0;i<3;i++){
            bear[i]=Integer.parseInt(br.readLine());
        }
        Arrays.sort(bear);
        System.out.println(bear[1]);
    }
}