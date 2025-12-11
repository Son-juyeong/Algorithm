import java.io.*;
import java.util.*;

public class Main {

    static int[] arr;
    static int[] record;
    static int[] lis;

    public static int binarySearch(int left, int right, int target){
        while(left<right){
            int mid = (left + right) / 2;
            int num = lis[mid];
            if(num<target){
                left = mid + 1;
            }else if(num>target){
                right = mid;
            } else return mid;
        }
        return right;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        arr = new int[500001];
        record = new int[500001];
        lis = new int[n+1];

        for(int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            arr[a] = b;
        }

        int len = 0;

        for(int i = 1;i<=500000;i++){
            int target = arr[i];
            if(target==0) continue;
            if(lis[len]<target){
                lis[++len] = target;
                record[i] = len;
            }else{
                int idx = binarySearch(0, len, target);
                lis[idx] = target;
                record[i] = idx;
            }
        }

        int cnt = n - len;
        int[] answer = new int[cnt];
        int idx = cnt - 1;

        for(int i = 500000;i>0;i--){
            if(record[i]==0) continue;
            if(record[i]==len){
                --len;
            }else{
                answer[idx--] = i;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(cnt).append("\n");
        for(int i = 0;i<cnt;i++){
            sb.append(answer[i]).append("\n");
        }

        System.out.println(sb);
    }
}