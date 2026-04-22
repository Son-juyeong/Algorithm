import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = new int[1000000];
        for(int i=0;i<10;i++){
            arr[i]=i;
        }
        int idx1 = 0, idx2=0;
        int idx3 = 10, idx4=10;
        for(int i = 1;i<10;i++){
            for(int j = i;j<=9;j++){
                for(int k = idx1;k<=idx2;k++){
                    arr[idx4]=j*(int)Math.pow(10, i)+arr[k];
                    idx4++;
                }
                while(true){
                    if(Integer.toString(arr[idx2]).charAt(0)-'0'==j){
                        int a = Integer.toString(arr[idx2]).charAt(0)-'0';
                        while(true){
                            if(Integer.toString(arr[idx2+1]).charAt(0)-'0'!=a)
                                break;
                            idx2++;
                        }
                        break;
                    }
                    idx2++;
                }

            }
            idx1=idx3;
            idx3=idx4;
            idx2=idx1;
        }
        int N = Integer.parseInt(br.readLine());
        if(N==1023)
            System.out.println("9876543210");
        else if(N>1023)
            System.out.println("-1");
        else System.out.println(arr[N-1]);
    }
}