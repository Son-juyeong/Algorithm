import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] stack = new int[N];
        int idx = -1;
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            switch(c){
                case 1:
                    int n = Integer.parseInt(st.nextToken());
                    stack[++idx]=n;
                    break;
                case 2:
                    if(idx==-1)
                        System.out.println(-1);
                    else{
                        System.out.println(stack[idx--]);
                    }
                    break;
                case 3:
                    System.out.println(idx+1);
                    break;
                case 4:
                    System.out.println(idx==-1?1:0);
                    break;
                case 5:
                    if(idx==-1)
                        System.out.println(-1);
                    else
                        System.out.println(stack[idx]);
                    break;
            }
        }
    }
}