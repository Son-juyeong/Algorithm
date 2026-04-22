import java.io.*;
import java.util.*;

public class Main {

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        String str = br.readLine();
        StringBuilder sb = new StringBuilder();
        while(!str.equals("#")){
            int cnt = 0;
            str = str.toLowerCase();
            for(int i = 0;i<str.length();i++){
                if(set.contains(str.charAt(i)))
                    ++cnt;
            }
            sb.append(cnt).append("\n");
            str = br.readLine();
        }
        System.out.println(sb);
    }
}