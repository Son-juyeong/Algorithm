import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int count = 0;
        while(str.length()!=1){
            int sum = 0;
            for(int i=0;i<str.length();i++){
                sum+=Integer.parseInt(str.substring(i, i+1));
            }
            count++;
            str = Integer.toString(sum);
        }
        System.out.println(count);
        if(Integer.parseInt(str)%3==0)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}