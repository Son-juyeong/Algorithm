import java.util.Scanner;

public class Main {
public static void main(String[] args) {
	int A=0;
	int B=0;
	int n, a ,b;
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	for(int i=0; i<n;i++) {
		a =sc.nextInt();
		b=sc.nextInt();
		if(a>b) {
			A++;
		}else if(a<b){
			B++;
		}
	}
	System.out.println(A+" "+B);
}
}