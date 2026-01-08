import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        if(N*N<=100000000){
            System.out.println("Accepted");
        }
        else{
            System.out.println("Time limit exceeded");
        }
    }
}