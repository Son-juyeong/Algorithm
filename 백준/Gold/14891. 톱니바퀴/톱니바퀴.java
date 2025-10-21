import java.io.*;
import java.util.*;

public class Main {

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 톱니바퀴
		String[] str = new String[5];
		// 12시 인덱스 번호
		int[] index = new int[5];

		for (int i = 1; i <= 4; i++) {
			str[i] = br.readLine();
		}

		int k = Integer.parseInt(br.readLine());

		for (int i = 0; i < k; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int dir = Integer.parseInt(st.nextToken());
			boolean[] different = new boolean[3];
			different[0] = str[1].charAt((index[1] + 2) % 8) != str[2].charAt((index[2] + 6) % 8);
			different[1] = str[2].charAt((index[2] + 2) % 8) != str[3].charAt((index[3] + 6) % 8);
			different[2] = str[3].charAt((index[3] + 2) % 8) != str[4].charAt((index[4] + 6) % 8);
			index[n] = (8 + index[n] - dir) % 8;
			switch (n) {
			case 1:
				int t = 0;
				while (different[t]) {
					dir *= -1;
					index[t + 2] = (8 + index[t + 2] - dir) % 8;
					++t;
					if (t == 3)
						break;
				}
				break;
			case 2:
				if (different[0])
					index[1] = (8 + index[1] + dir) % 8;
				if (different[1]) {
					index[3] = (8 + index[3] + dir) % 8;
					if (different[2]) {
						index[4] = (8 + index[4] - dir) % 8;
					}
				}
				break;
			case 3:
				if (different[2])
					index[4] = (8 + index[4] + dir) % 8;
				if (different[1]) {
					index[2] = (8 + index[2] + dir) % 8;
					if (different[0]) {
						index[1] = (8 + index[1] - dir) % 8;
					}
				}
				break;
			case 4:
				t = 2;
				while (different[t]) {
					dir *= -1;
					index[t + 1] = (8 + index[t + 1] - dir) % 8;
					--t;
					if (t == -1)
						break;
				}
				break;
			}
		}

		int answer = 0;
		for (int i = 1; i <= 4; i++) {
			answer += str[i].charAt(index[i]) == '1' ? 1 << (i - 1) : 0;
		}
		System.out.println(answer);
	}
}