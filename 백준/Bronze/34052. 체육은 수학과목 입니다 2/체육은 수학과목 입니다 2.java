import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int sec = 1500;
        for(int i=0;i<4;i++){
            sec -= Integer.parseInt(br.readLine());
        }
        System.out.println(sec>=0?"Yes":"No");
    }
}