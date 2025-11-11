import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] arr = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int answer = 0;

        for(int i = 0;i<N;i++){
            int temp = 0;
            for(int j = 0;j<N;j++){
                if(i==j) continue;
                boolean find = true;
                double a = (double)(arr[i]-arr[j])*1000000000/(i-j);
                double b = arr[i] * 1000000000 - a * i;
                for(int k = Math.min(i, j)+1; k<(Math.max(i, j)); k++){
                    if(arr[k]*1000000000>=a*k+b){
                        find=false;
                        break;
                    }
                }
                if(find) ++temp;
            }
            answer = Math.max(answer, temp);
        }
        System.out.println(answer);
    }
}