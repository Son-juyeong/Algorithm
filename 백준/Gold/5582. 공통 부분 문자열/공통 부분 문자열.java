import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 String str1 = br.readLine();
		 String str2 = br.readLine();
		 
		 int[][] dp = new int[str1.length()+1][str2.length()+1];
		 
		 for(int i = 0;i<str1.length();i++) {
			 for(int j = 0;j<str2.length();j++) {
				 if(str1.charAt(i)==str2.charAt(j)) {
					 dp[i+1][j+1]=dp[i][j]+1;
				 }
			 }
		 }
		 
		 int answer = 0;
		 
		 for(int i = 1;i<=str1.length();i++) {
			 for(int j = 1;j<=str2.length();j++) {
				 answer = Math.max(answer, dp[i][j]);
			 }
		 }
		 
		 System.out.println(answer);
	}
}