import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        String[] arr = new String[n];

        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }

        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() == o2.length()) {
                    int sum1 = 0, sum2 = 0;
                    for (int i = 0; i < o1.length(); i++) {
                        char c1 = o1.charAt(i);
                        if (Character.isDigit(c1)) {
                            sum1 += Character.getNumericValue(c1);
                        }
                        char c2 = o2.charAt(i);
                        if (Character.isDigit(c2)) {
                            sum2 += Character.getNumericValue(c2);
                        }
                    }
                    if (sum1 == sum2) {
                        return o1.compareTo(o2);
                    }
                    return sum1 - sum2;
                }
                return o1.length() - o2.length();
            }
        });

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < n; i++) {
            sb.append(arr[i]).append("\n");
        }
        System.out.println(sb);
    }
}