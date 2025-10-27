import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int[][] weight = new int[n+1][n+1];
        for(int i = 1;i<=n;i++){
            Arrays.fill(weight[i], 10000000);
            weight[i][i]=0;
        }

        for(int k = 0;k<m;k++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());
            weight[i][j] = Math.min(Integer.parseInt(st.nextToken()), weight[i][j]);
        }

        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(weight[i][k]+weight[k][j]<weight[i][j]){
                        weight[i][j]=weight[i][k]+weight[k][j];
                    }
                }
            }
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                System.out.print((weight[i][j]==10000000?0:weight[i][j])+" ");
            }
            System.out.println();
        }
    }
}