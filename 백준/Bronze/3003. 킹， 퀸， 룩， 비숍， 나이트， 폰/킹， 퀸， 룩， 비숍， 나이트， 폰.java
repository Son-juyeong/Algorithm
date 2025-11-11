import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        int[] arr = {1, 1, 2, 2, 2, 8};
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        StringBuilder sb = new StringBuilder();
        for(int i = 0;i<6;i++){
            int n = Integer.parseInt(st.nextToken());
            sb.append(arr[i] - n).append(" ");
        }

        System.out.println(sb);
    }
}