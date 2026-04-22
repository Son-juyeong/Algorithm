import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String id = br.readLine();
        String sb = ":fan::fan::fan:\n" +
                ":fan::" + id + "::fan:\n" +
                ":fan::fan::fan:";
        System.out.println(sb);
    }
}