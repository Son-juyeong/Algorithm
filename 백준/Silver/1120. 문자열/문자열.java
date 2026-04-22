import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = bf.readLine();
        String[] array = str.split(" ");
        int answer = 51;
        for(int i=0;i<array[1].length()-array[0].length()+1;i++){
            int temp = 0;
            for(int j=0;j<array[0].length();j++){
                if(array[0].charAt(j)!=array[1].charAt(i+j))
                    temp++;
            }
            answer = Math.min(answer, temp);
        }
        System.out.println(answer);
    }
}