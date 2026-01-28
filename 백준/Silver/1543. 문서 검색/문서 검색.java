import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();

        int answer = 0;

        for (int i = 0; i <= str1.length() - str2.length(); i++) {
            if (str2.compareTo(str1.substring(i, i + str2.length())) == 0) {
                ++answer;
                i += str2.length() - 1;
            }
        }
        System.out.println(answer);
    }
}
