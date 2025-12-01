import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        while(n!=0){
            sb.append((n + 1) * n / 2).append("\n");
            n = Integer.parseInt(br.readLine());
        }
        System.out.println(sb);
    }
}