import java.io.*;
import java.util.*;

public class Main {

    // dfs를 사용하여 cctv 각도별 사각지대 확인하기
    // cctv 설치 끝나고 다시 돌아서 사각지대 확인하면 시간이 모자랄 것 같으니, 설치하면서 개수 세기
    // 1번은 for문 4번, 2번은 for문 가로 세로 2번, 3번과 4번은 for문 방항별 for문 4번, 5번은 한번
    // dfs 넘길 때 사각지대 개수, index 매개변수로 넘기기
    // cctv 안으로 들어오는 부분은 arr에 7로 표기하기
    // cctv 시야에 잡히는 부분은 dfs내에서 list를 만들어서 그 부분만큼만 관리(?)
    // cctv 시야에 들어오는지 확인하는 메서드를 생성하여 list 반환

    public static int[] dr = {-1,0,1,0};
    public static int[] dc = {0, 1, 0, -1};
    public static int[][] arr;
    public static int N;
    public static int M;
    public static List<Integer[]> cctvList;
    public static int answer;

    public static void dfs(int depth, int cnt){
        if(cnt==0){
            answer = 0;
            return;
        }
        if(depth==cctvList.size()){
            answer = Math.min(answer, cnt);
            return;
        }
        int r = cctvList.get(depth)[0];
        int c = cctvList.get(depth)[1];
        switch(arr[r][c]){
            case 1:
                for(int i = 0;i<4;i++){
                    List<Integer[]> monitoringList = checkMonitoringArea(r, c, i);
                    monitoring(monitoringList, 7);
                    dfs(depth+1, cnt-monitoringList.size());
                    monitoring(monitoringList, 0);
                }
                break;
            case 2:
                for(int i = 0;i<2;i++){
                    List<Integer[]> monitoringList1 = checkMonitoringArea(r, c, i);
                    List<Integer[]> monitoringList2 = checkMonitoringArea(r, c, i+2);
                    monitoringList1.addAll(monitoringList2);
                    monitoring(monitoringList1, 7);
                    dfs(depth+1, cnt-monitoringList1.size());
                    monitoring(monitoringList1, 0);
                }
                break;
            case 3:
                for(int i = 0;i<4;i++){
                    List<Integer[]> monitoringList1 = checkMonitoringArea(r, c, i);
                    List<Integer[]> monitoringList2 = checkMonitoringArea(r, c, (i+1)%4);
                    monitoringList1.addAll(monitoringList2);
                    monitoring(monitoringList1, 7);
                    dfs(depth+1, cnt-monitoringList1.size());
                    monitoring(monitoringList1, 0);
                }
                break;
            case 4:
                for(int i = 0;i<4;i++){
                    List<Integer[]> monitoringList1 = checkMonitoringArea(r, c, i);
                    List<Integer[]> monitoringList2 = checkMonitoringArea(r, c, (i+1)%4);
                    List<Integer[]> monitoringList3 = checkMonitoringArea(r, c, (i+2)%4);
                    monitoringList1.addAll(monitoringList2);
                    monitoringList1.addAll(monitoringList3);
                    monitoring(monitoringList1, 7);
                    dfs(depth+1, cnt-monitoringList1.size());
                    monitoring(monitoringList1, 0);
                }
                break;
            case 5:
                List<Integer[]> monitoringList = new ArrayList<>();
                for(int i = 0;i<4;i++){
                    monitoringList.addAll(checkMonitoringArea(r, c, i));
                }
                monitoring(monitoringList, 7);
                dfs(depth+1, cnt-monitoringList.size());
                monitoring(monitoringList, 0);
                break;
        }
    }

    public static List<Integer[]> checkMonitoringArea(int r, int c, int dir){
        List<Integer[]> list = new ArrayList<>();
        while(true){
            r+=dr[dir];
            c+=dc[dir];
            if(isWall(r, c)) break;
            if(isContinue(r, c)) continue;
            list.add(new Integer[]{r, c});
        }
        return list;
    }

    public static void monitoring(List<Integer[]> list, int t){
        for(int i = 0;i<list.size();i++){
            int r = list.get(i)[0];
            int c = list.get(i)[1];
            arr[r][c]=t;
        }
    }

    public static boolean isWall(int r, int c){
        return r<0||r>=N||c<0||c>=M||arr[r][c]==6;
    }

    public static boolean isContinue(int r, int c){
        return 1<=arr[r][c]&&arr[r][c]<=5||arr[r][c]==7;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N][M];
        cctvList = new ArrayList<>();

        answer = 0;

        for(int i = 0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0;j<M;j++){
                arr[i][j]=Integer.parseInt(st.nextToken());
                if(1<=arr[i][j]&&arr[i][j]<=5){
                    cctvList.add(new Integer[]{i, j});
                }
                else if(arr[i][j]==0)
                    answer++;
            }
        }

        dfs(0, answer);

        System.out.println(answer);
    }
}