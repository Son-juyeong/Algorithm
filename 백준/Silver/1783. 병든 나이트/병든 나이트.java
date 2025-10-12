import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        if(n<3){
            if(n==1)
                System.out.println(1);
            else
                System.out.println(Math.min((1 + (m - 1) / 2), 4));
        }
        else if(m<7){
            if(m<5){
                System.out.println(m);
            }
            else{
                System.out.println(4);
            }
        }
        else{
            System.out.println(3+(m-5));
        }
    }
}