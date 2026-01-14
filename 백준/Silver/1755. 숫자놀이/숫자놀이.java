import java.io.*;
import java.util.*;

public class Main {

    static class Node implements Comparable<Node>{
        int num;
        String str;
        public Node(int num, String str){
            this.num = num;
            this.str = str;
        }

        @Override
        public int compareTo(Node o) {
            return this.str.compareTo(o.str);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        List<Node> list = new ArrayList<>();
        Map<Character, String> map = new HashMap<>();
        map.put('0', "zero");
        map.put('1', "one");
        map.put('2', "two");
        map.put('3', "three");
        map.put('4', "four");
        map.put('5', "five");
        map.put('6', "six");
        map.put('7', "seven");
        map.put('8', "eight");
        map.put('9', "nine");

        for(int i = m;i<=n;i++){
            String str = Integer.toString(i);
            StringBuilder temp = new StringBuilder();
            for(int j = 0;j<str.length();j++){
                temp.append(map.get(str.charAt(j)));
            }
            list.add(new Node(i, temp.toString()));
        }
        Collections.sort(list);

        StringBuilder sb = new StringBuilder();

        for(int i = 0; i<list.size();i++){
            sb.append(list.get(i).num).append(" ");
            if(i%10==9) sb.append("\n");
        }
        System.out.println(sb);
    }
}