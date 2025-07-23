import java.io.*;
import java.util.*;

public class Main {

    static long A, B, C;

//    지수법칙 : a^(n+m) = a^n * a^m
//    모듈러 성질 : (a*b)%c = (a%c * b%c)%c
    public static long func(long b){
        if(b==0) return 1;
        if(b==1) return A%C;
        long t = func(b/2);
        if(b%2==1) return t*t%C*A%C;
        else return t*t%C;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A=Long.parseLong(st.nextToken());
        B=Long.parseLong(st.nextToken());
        C=Long.parseLong(st.nextToken());
        long answer = func(B);
        System.out.println(answer);
    }
}