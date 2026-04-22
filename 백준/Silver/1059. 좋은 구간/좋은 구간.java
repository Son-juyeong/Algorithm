import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();
        List<Integer> S = new ArrayList<>();
        for(int i=0;i<L;i++){
            int t = sc.nextInt();
            S.add(t);
        }
        S.sort(Comparator.naturalOrder());
        int n = sc.nextInt();
        int answer = 0;
        for(int i=0;i<L;i++){
            int t = S.get(i);
            if(n==t) break;
            else if(n<t){
                if(i==0){
                    answer=(n-1)*(t-n)+t-n-1;
                }
                else{
                    answer=(n-S.get(i-1)-1)*(t-n)+t-n-1;
                }
                break;
            }
        }
        System.out.println(answer);
    }
}