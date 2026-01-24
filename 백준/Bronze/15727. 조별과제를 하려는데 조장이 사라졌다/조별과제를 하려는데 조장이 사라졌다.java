import java.io.*;
import java.util.*;

public class Main{
  public static void main(String[] agrs) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());
    System.out.println((t+4)/5);
  }
}