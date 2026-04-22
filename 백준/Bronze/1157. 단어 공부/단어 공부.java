import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine().toUpperCase();

        int[] cnt = new int[26];

        for(int i = 0;i<str.length();i++){
            ++cnt[str.charAt(i) - 'A'];
        }

        char answer = '?';
        int maxCnt = 0;

        for(int i = 0;i<26;i++){
            if(cnt[i]>maxCnt){
                maxCnt = cnt[i];
                answer = (char)(i + 'A');
            }
            else if(cnt[i]==maxCnt){
                answer = '?';
            }
        }

        System.out.println(answer);
    }
}