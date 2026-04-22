import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int[][] arr = new int[26][str.length()+1];
        for(int i=1;i<=str.length();i++){
            for(int j=0;j<26;j++)
                arr[j][i]=arr[j][i-1];
            arr[str.charAt(i-1)-'a'][i]++;
        }
        int n = Integer.parseInt(br.readLine());
        StringBuilder answer = new StringBuilder();
        for(int i=0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            char c = st.nextToken().charAt(0);
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            answer.append(arr[c-'a'][r+1]-arr[c-'a'][l]+"\n");
        }
        System.out.println(answer);
    }
}