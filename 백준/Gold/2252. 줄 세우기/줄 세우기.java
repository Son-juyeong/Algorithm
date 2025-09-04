import java.io.*;
import java.util.*;

public class Main {

	static class Node {
		int vertex;
		Node link;

		public Node(int vertex, Node link) {
			this.vertex = vertex;
			this.link = link;
		}
	}

	static int N, M;

	static int[] inDegree;
	static Node[] node;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		node = new Node[N + 1];
		inDegree = new int[N + 1];

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int from, to;
			
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			
			node[from] = new Node(to, node[from]);
			inDegree[to]++;
		}
		
		Queue<Integer> q = new ArrayDeque<>();
		for(int i = 1;i<=N;i++) {
			if(inDegree[i]==0) {
				q.offer(i);
			}
		}
		
		while(!q.isEmpty()) {
			int cur = q.poll();
			sb.append(cur+" ");
			for(Node temp = node[cur];temp!=null;temp=temp.link) {
				if(--inDegree[temp.vertex]==0) {
					q.offer(temp.vertex);
				}
			}
		}
		
		System.out.println(sb);
	}
}