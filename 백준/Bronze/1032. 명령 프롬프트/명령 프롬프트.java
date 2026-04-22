import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        String answer = sc.nextLine();
        for(int i=0;i<N-1;i++){
            String str = sc.nextLine();
            for (int j = 0; j < answer.length(); j++) {
                if(answer.charAt(j)!=str.charAt(j)){
                    StringBuilder strb = new StringBuilder(answer);
                    strb.setCharAt(j, '?');
                    answer = strb.toString();
                }
            }
        }
        System.out.println(answer);
    }
}