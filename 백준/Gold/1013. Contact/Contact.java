import java.util.Scanner;

public class Main {

    static String answer = "NO";

    static enum State{
        S1, S2, S3, S4
    }

    static void dfs(State s, String str, int idx){
        if(str.length()==idx){
            if(s==State.S3||s==State.S4)
                answer = "YES";
            return;
        }
        if(s==State.S1){
            if(str.charAt(idx)=='0'){
                dfs(State.S2, str, idx+1);
            }
        }
        else if(s==State.S2){
            if(str.charAt(idx)=='0'){
                dfs(State.S2, str, idx+1);
            }
            else{
                dfs(State.S3, str, idx+1);
            }
        }
        else if(s==State.S3){
            if(str.charAt(idx)=='1'){
                dfs(State.S3, str, idx+1);
                if(idx<str.length()-1&&str.charAt(idx+1)=='0'){
                    dfs(State.S1, str, idx+2);
                }
            }
            else{
                if(idx<str.length()-1&&str.charAt(idx+1)=='1'){
                    dfs(State.S4, str, idx+2);
                }
            }
        }
        else{
            if(idx<str.length()-1) {
                if (str.charAt(idx) == '1' && str.charAt(idx + 1) == '0') {
                    dfs(State.S1, str, idx + 2);
                } else if (str.charAt(idx) == '0' && str.charAt(idx + 1) == '1') {
                    dfs(State.S4, str, idx + 2);
                }
            }
        }
    }

    public static void main(String[] args) {
        int n = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();
        for(int i =0;i<n;i++){
            answer = "NO";
            String s = sc.nextLine();
            if(s.length()>=2){
                if(s.charAt(0)=='1'&&s.charAt(1)=='0'){
                    dfs(State.S1, s, 2);
                }
                else if(s.charAt(0)=='0'&&s.charAt(1)=='1'){
                    dfs(State.S4, s, 2);
                }
            }
            System.out.println(answer);
        }
    }
}