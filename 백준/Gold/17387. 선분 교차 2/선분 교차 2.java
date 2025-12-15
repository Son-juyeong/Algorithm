import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(st.nextToken());
        int y1 = Integer.parseInt(st.nextToken());
        int x2 = Integer.parseInt(st.nextToken());
        int y2 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int x3 = Integer.parseInt(st.nextToken());
        int y3 = Integer.parseInt(st.nextToken());
        int x4 = Integer.parseInt(st.nextToken());
        int y4 = Integer.parseInt(st.nextToken());

        if(x1==x3&&y1==y3||x1==x4&&y1==y4||x2==x3&&y2==y3||x2==x4&&y2==y4){
            System.out.println(1);
            return;
        }

        if(x1==x2&&x3==x4){
            if(x1!=x3){
                System.out.println(0);
                return;
            }
            if(Math.max(y1, y2)<Math.min(y3, y4)||Math.max(y3, y4)<Math.min(y1, y2))
                System.out.println(0);
            else
                System.out.println(1);
            return;
        }
        else if(x1==x2){
            if(Math.min(x3, x4)>x1||Math.max(x3, x4)<x1){
                System.out.println(0);
                return;
            }
            float a = (float) (y4 - y3) / (x4 - x3);
            float b = y3 - (a * x3);
            float t = a * x1 + b;
            if(Math.min(y1, y2)<=t&&t<=Math.max(y1, y2)){
                System.out.println(1);
            }else System.out.println(0);
            return;
        }else if(x3==x4){
            if(Math.min(x1, x2)>x3||Math.max(x1, x2)<x3){
                System.out.println(0);
                return;
            }
            float a = (float) (y2 - y1) / (x2 - x1);
            float b = y1 - (a * x1);
            float t = a * x3 + b;
            if(Math.min(y3, y4)<=t&&t<=Math.max(y3, y4)){
                System.out.println(1);
            }else System.out.println(0);
            return;
        }else if(y1==y2&&y3==y4){
            if(y1!=y3){
                System.out.println(0);
                return;
            }
            if(Math.max(x1, x2)<Math.min(x3, x4)||Math.max(x3, x4)<Math.min(x1, x2))
                System.out.println(0);
            else System.out.println(1);
            return;
        }else if(y1==y2){
            float a = (float) (y4 - y3) / (x4 - x3);
            float b = y3 - (a * x3);
            float x = (y1 - b) / a;
            if(Math.min(x1, x2)<=x&&x<=Math.max(x1, x2))
                System.out.println(1);
            else System.out.println(0);
            return;
        }
        else if(y3==y4){
            float a = (float) (y2 - y1) / (x2 - x1);
            float b = y1 - (a * x1);
            float x = (y3 - b) / a;
            if(Math.min(x3, x4)<=x&&x<=Math.max(x3, x4))
                System.out.println(1);
            else System.out.println(0);
            return;
        }

        float a1 = (float) (y2 - y1) / (x2 - x1);
        float b1 = y1 - (a1 * x1);

        float a2 = (float) (y4 - y3) / (x4 - x3);
        float b2 = y3 - (a2 * x3);

        if(a1==a2){
            if(b1==b2){
                if(Math.max(x1, x2)<Math.min(x3, x4)||Math.max(x3, x4)<Math.min(x1, x2)){
                    System.out.println(0);
                }else{
                    System.out.println(1);
                }
            }
            else{
                System.out.println(0);
            }
        }
        else{
            float x = Math.round((b2 - b1) / (a1 - a2));
            if(Math.min(x1, x2)<=x&&x<=Math.max(x1, x2)&&Math.min(x3, x4)<=x&&x<=Math.max(x3, x4)){
                System.out.println(1);
            }else System.out.println(0);
        }
    }
}