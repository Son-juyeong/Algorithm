import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //row -> left, col -> right
        int[][][] dp = new int[100001][5][5];
        for (int i = 0; i <= 100000; i++) {
            for(int j = 0;j<5;j++){
                Arrays.fill(dp[i][j], 500000);
            }

        }

        dp[0][0][0] = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());

        int input = Integer.parseInt(st.nextToken());

        int idx = 0;

        while (input != 0) {
            for (int i = 0; i < 5; i++) {
                int left = 0;
                if(i==0){
                    left=2;
                }else if(i==input){
                    left=1;
                }else if(Math.abs(i-input)==2){
                    left=4;
                }else{
                    left=3;
                }
                for (int j = 0; j < 5; j++) {
                    int right = 0;
                    if(j==0){
                        right=2;
                    }else if(j==input){
                        right=1;
                    }else if(Math.abs(j-input)==2){
                        right=4;
                    }else{
                        right=3;
                    }
                    dp[idx+1][input][j] = Math.min(dp[idx+1][input][j], dp[idx][i][j]+left);
                    dp[idx+1][i][input] = Math.min(dp[idx+1][i][input], dp[idx][i][j]+right);
                }
            }
            ++idx;
            input = Integer.parseInt(st.nextToken());
        }

        int answer = Integer.MAX_VALUE;
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                answer = Math.min(answer, dp[idx][i][j]);
            }
        }

        System.out.println(answer);
    }
}