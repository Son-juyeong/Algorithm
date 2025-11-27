import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        char[][] arr = new char[N][N];
        for(int i = 0;i<N;i++){
            String str = br.readLine();
            for(int j = 0;j<N;j++){
                arr[i][j] = str.charAt(j);
            }
        }
        int answer = 0;
        for(int i =0;i<N;i++){
            int temp = 0;
            Set<Integer> friend = new TreeSet<>();
            for(int j = 0;j<N;j++){
                if(arr[i][j]=='Y'){
                    ++temp;
                    friend.add(j);
                }
            }
            Iterator<Integer> iter = friend.iterator();
            TreeSet<Integer> twoFriend = new TreeSet<>();
            while(iter.hasNext()){
                int j = iter.next();
                for(int k = 0;k<N;k++){
                    if(arr[j][k]=='Y'&&!twoFriend.contains(k)&&!friend.contains(k)&&k!=i){
                        ++temp;
                        twoFriend.add(k);
                    }
                }
            }
            answer = Math.max(answer, temp);
        }
        System.out.println(answer);
    }
}