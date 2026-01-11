import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            int num = Integer.parseInt(st.nextToken());
            a[i] = a[i - 1] + num;
        }
        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] b = new int[m + 1];
        for (int i = 1; i <= m; i++) {
            int num = Integer.parseInt(st.nextToken());
            b[i] = b[i - 1] + num;
        }

        Set<Integer> aTreeSet = new TreeSet<>();
        Set<Integer> bTreeSet = new TreeSet<>();

        Map<Integer, Integer> aHashMap = new HashMap<>();
        Map<Integer, Integer> bHashMap = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int temp = a[j] - a[i - 1];
                aTreeSet.add(temp);
                if(aHashMap.containsKey(temp)){
                    aHashMap.replace(temp, aHashMap.get(temp)+1);
                }else{
                    aHashMap.put(temp, 1);
                }
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= m; j++) {
                int temp = b[j] - b[i - 1];
                bTreeSet.add(temp);
                if(bHashMap.containsKey(temp)){
                    bHashMap.replace(temp, bHashMap.get(temp)+1);
                }else{
                    bHashMap.put(temp, 1);
                }
            }
        }

        Integer[] aArray = aTreeSet.toArray(new Integer[0]);
        Integer[] bArray = bTreeSet.toArray(new Integer[0]);

        long answer = 0;

        for(int i = 0;i<aArray.length;i++){
            int temp = aArray[i];
            int left = 0, right = bArray.length - 1;
            while(left<=right){
                int middle = (left + right) / 2;
                int sum = temp + bArray[middle];
                if(sum==T){
                    answer += (long) aHashMap.get(temp) * bHashMap.get(bArray[middle]);
                    break;
                }else if(sum>T){
                    right = middle - 1;
                }else{
                    left = middle + 1;
                }
            }
        }

        System.out.println(answer);
    }
}