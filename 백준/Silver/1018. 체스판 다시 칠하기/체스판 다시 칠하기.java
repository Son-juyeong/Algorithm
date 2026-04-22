import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        char[][] arr = new char[N+1][M+1];
        for(int i=1;i<=N;i++){
            String str = br.readLine();
            for(int j = 1;j<=M;j++){
                arr[i][j] = str.charAt(j-1);
            }
        }
        int w[][] = new int[N+1][M+1];
        int b[][] = new int[N+1][M+1];
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                w[i][j]=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
                b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
                if(i%2==1){
                    if(j%2==1)
                        if(arr[i][j]=='B')
                            w[i][j]++;
                        else b[i][j]++;
                    else{
                        if(arr[i][j]=='B')
                            b[i][j]++;
                        else w[i][j]++;
                    }
                }
                else{
                    if(j%2==1)
                        if(arr[i][j]=='B')
                            b[i][j]++;
                        else w[i][j]++;
                    else{
                        if(arr[i][j]=='B')
                            w[i][j]++;
                        else b[i][j]++;
                    }
                }
            }
        }
        int answer = 32;
        for(int i=8;i<=N;i++){
            for(int j = 8;j<=M;j++){
                answer = Math.min(answer, w[i][j]-w[i-8][j]-w[i][j-8]+w[i-8][j-8]);
                answer = Math.min(answer, b[i][j]-b[i-8][j]-b[i][j-8]+b[i-8][j-8]);
            }
        }
        System.out.println(answer);
    }
}