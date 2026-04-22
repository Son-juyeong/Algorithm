import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        String upper = str.toUpperCase();
        String lower = str.toLowerCase();
        StringBuilder sb = new StringBuilder(str);
        for(int i = 0;i<sb.length();i++){
            if(sb.charAt(i)>='a'){
                sb.setCharAt(i, upper.charAt(i));
            }
            else
                sb.setCharAt(i, lower.charAt(i));
        }
        System.out.println(sb);
    }
}