import java.util.*;
import java.io.*;

public class Main {

	static class Node{
		int value;
		int next;
		public Node(int value, int next) {
			this.value=value;
			this.next=next;
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		
		int N = sc.nextInt();
		
		Node[] dp = new Node[N+1];
		dp[1] = new Node(0, 1);
		
		for(int i = 2;i<=N;i++) {
			int value = dp[i-1].value+1;
			int next = i-1;
			if(i%2==0) {
				int tempNext = i/2;
				int tempValue = dp[tempNext].value+1;
				if(tempValue<value) {
					value=tempValue;
					next=tempNext;
				}
			}
			if(i%3==0) {
				int tempNext = i/3;
				int tempValue = dp[tempNext].value+1;
				if(tempValue<value) {
					value=tempValue;
					next=tempNext;
				}
			}
			dp[i] = new Node(value, next);
		}
		
		sb.append(dp[N].value).append("\n");
		
		int idx = N;
		while(idx!=dp[idx].next) {
			sb.append(idx).append(" ");
			idx=dp[idx].next;
		}
		sb.append(1);
		
		System.out.println(sb);
	}
}