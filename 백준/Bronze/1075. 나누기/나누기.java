import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int f = Integer.parseInt(br.readLine());
        n = n/100*100;
        if(n%f==0)
            System.out.println("00");
        else{
            int t = (n/f+1)*f;
            String str = Integer.toString(t);
            System.out.println(str.substring(str.length()-2));
        }
    }
}