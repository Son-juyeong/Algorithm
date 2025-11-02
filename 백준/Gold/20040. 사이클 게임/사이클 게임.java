import java.io.*;
import java.util.*;

public class Main {

    static int[] parent;
    static int[] level;

    static void init(int n){
        parent = new int[n];
        level = new int[n];
        for(int i = 0;i<n;i++){
            parent[i] = i;
            level[i] = 1;
        }
    }

    static int find(int n){
        if(parent[n]==n)
            return n;
        return parent[n] = find(parent[n]);
    }

    static boolean union(int x, int y){
        int parentX = find(x);
        int parentY = find(y);
        if(parentX==parentY)
            return false;
        if(level[parentX]>level[parentY]){
            parent[parentY]=parentX;
        }
        else parent[parentX]=parentY;
        if(level[parentX]==level[parentY])
            level[parentY]++;
        return true;
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        init(n);

        int answer = 0;

        for(int i = 1;i<=m;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if(!union(x, y)&&answer==0){
                answer=i;
            }
        }
        System.out.println(answer);
    }
}