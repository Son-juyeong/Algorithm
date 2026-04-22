import java.util.Scanner;

public class Main {

    static int[][] dp = new int[41][2];

    public static void main(String[] args) {
        dp[0][0]=1;
        dp[0][1]=0;
        dp[1][0]=0;
        dp[1][1]=1;
        for(int i=2;i<=40;i++){
            dp[i][0]+=dp[i-1][0]+dp[i-2][0];
            dp[i][1]+=dp[i-1][1]+dp[i-2][1];
        }
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        for(int i=0;i<t;i++){
            int n = Integer.parseInt(sc.nextLine());
            System.out.println(dp[n][0]+" "+dp[n][1]);
        }
    }
}