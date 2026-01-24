import java.io.*;
import java.util.*;

public class Main {

    static class Pos {
        int r;
        int c;

        public Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        char[][] arr = new char[N + 1][N + 1];

        for (int i = 1; i <= N; i++) {
            String str = br.readLine();
            for (int j = 1; j <= N; j++) {
                arr[i][j] = str.charAt(j - 1);
            }
        }

        Pos heart = new Pos(0, 0);

        for (int i = 1; i <= N; i++) {
            boolean find = false;
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] == '*') {
                    heart.r = i + 1;
                    heart.c = j;
                    find = true;
                    break;
                }
            }
            if (find) break;
        }

        int armL = 1, armR = N - heart.c;

        for (int i = 1; i < heart.c; i++) {
            if (arr[heart.r][i] == '*') {
                armL = heart.c - i;
                break;
            }
        }

        for (int i = heart.c + 2; i <= N; i++) {
            if (arr[heart.r][i] == '_') {
                armR = i - (heart.c + 1);
                break;
            }
        }

        int waist = 1;
        for (int i = heart.r + 2; i <= N; i++) {
            if (arr[i][heart.c] == '_') {
                waist = i - (heart.r + 1);
                break;
            }
        }

        int legL = N - (heart.r + waist);
        int legR = legL;

        for (int i = heart.r + waist + 2; i <= N; i++) {
            if (arr[i][heart.c - 1] == '_') {
                legL = i - (heart.r + waist + 1);
                break;
            }
        }

        for (int i = heart.r + waist + 2; i <= N; i++) {
            if (arr[i][heart.c + 1] == '_') {
                legR = i - (heart.r + waist + 1);
                break;
            }
        }

        System.out.println(heart.r + " " + heart.c);
        System.out.println(armL + " " + armR + " " + waist + " " + legL + " " + legR);
    }
}
