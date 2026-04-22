import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int count = 1;
        int answer = 666;
        while(count!=N){
            answer++;
            if(Integer.toString(answer).contains("666"))
                count++;
        }
        System.out.println(answer);
    }
}