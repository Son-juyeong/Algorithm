import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        BigInteger answer = BigInteger.ONE;
        for (int i = 2; i <= N; i++) {
            answer = answer.multiply(BigInteger.valueOf(i));
        }
        System.out.println(answer);
    }
}