import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList arrayList = new ArrayList();
        for(int i=1;i<=n;i++){
            arrayList.add(i);
        }
        int idx = 0;
        int count = 0;
        for(int i=0;i<m;i++){
            int t = sc.nextInt();
            int arrIdx = arrayList.indexOf(t);
            int size = arrayList.size();
            int a = (size+arrIdx-idx)%size;
            int b = (size+idx-arrIdx)%size;
            count += (a > b) ? b : a;
            arrayList.remove(arrIdx);
            if(size==1) break;
            idx = arrIdx%(size-1);
        }
        System.out.println(count);
    }
}