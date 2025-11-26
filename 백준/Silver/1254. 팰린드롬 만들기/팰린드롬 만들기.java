import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int length = str.length();
        for (int i = 0; i <= length; i++) {
            StringBuilder sb = new StringBuilder(str);
            for (int j = i - 1; j >= 0; j--) {
                sb.append(str.charAt(j));
            }
            int left = 0, right = sb.length() - 1;
            boolean palindrome = true;
            while (left <= right) {
                if (sb.charAt(left) != sb.charAt(right)) {
                    palindrome = false;
                    break;
                }
                ++left;
                --right;
            }
            if (palindrome) {
                System.out.println(sb.length());
                return;
            }
        }
    }
}