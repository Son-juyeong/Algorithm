import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][][] abc = new int[21][21][21];
        for(int i=0;i<21;i++){
            for(int j=0;j<21;j++){
                abc[0][i][j]=1;
                abc[i][0][j]=1;
                abc[i][j][0]=1;
            }
        }
        for(int i=1;i<21;i++){
            for(int j=1;j<21;j++){
                for(int k=1;k<21;k++){
                    if(i<j&&j<k){
                        abc[i][j][k]=abc[i][j][k-1]+abc[i][j-1][k-1]-abc[i][j-1][k];
                    }
                    else
                        abc[i][j][k]=abc[i-1][j][k]+abc[i-1][j-1][k]+abc[i-1][j][k-1]-abc[i-1][j-1][k-1];
                }
            }
        }

        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if(a==-1&&b==-1&&c==-1) break;
            int answer = 1;
            if(a<=0||b<=0||c<=0){
                answer = 1;
            }
            else if(a>20||b>20||c>20)
                answer = abc[20][20][20];
            else
                answer = abc[a][b][c];
            System.out.printf("w(%d, %d, %d) = %d\n", a, b, c, answer);
        }
    }
}