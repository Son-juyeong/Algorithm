import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String s = br.readLine();

        if(s.equals("NLCS")){
            bw.write("North London Collegiate School");
        }else if(s.equals("BHA")){
            bw.write("Branksome Hall Asia");
        }else if(s.equals("KIS")){
            bw.write("Korea International School");
        }else if(s.equals("SJA")){
            bw.write("St. Johnsbury Academy");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}