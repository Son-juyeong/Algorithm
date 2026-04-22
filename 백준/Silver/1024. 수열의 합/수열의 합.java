import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int N, L;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();
        List<Integer> answer = new ArrayList<>();
        for(int l=L;l<=100;l++){
            for(int i=N/l-l>0?N/l-l:0;i<N;i++){
                int t = 0;
                for(int j=i;j<i+l;j++){
                    t+=j;
                }
                if(t>N) break;
                else if(t==N){
                    for(int j=i;j<i+l;j++){
                        answer.add(j);
                    }
                }
            }
            if(answer.size()!=0) break;
        }
        if(answer.size()!=0){
            for(int i=0;i<answer.size();i++)
                System.out.print(answer.get(i)+" ");
        }
        else System.out.println(-1);
    }
}