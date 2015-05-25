import java.math.BigInteger;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.util.Scanner;

public class a{
	public static byte[][] p = new byte[4][2000];
	public static void main(String args[]){
		int test = 449;
		for(int i=0;i<32;i++){
			System.out.print(test&1);
			test>>=1;
		}
		System.out.println();
		
		Scanner cin = new Scanner(System.in);
		int n,t;
		BigInteger a,x,b,y;
		t=cin.nextInt();
		for(int cas=1;cas<=t;cas++){
			n = cin.nextInt();
			a = cin.nextBigInteger().subtract(BigInteger.ONE);
			x = cin.nextBigInteger().subtract(BigInteger.ONE);
			b = cin.nextBigInteger().subtract(BigInteger.ONE);
			y = cin.nextBigInteger().subtract(BigInteger.ONE);
			
			
			for(int i=0;i<4;i++)
				for(int j=0;j<=(n/8);j++)
					p[i][j] = 0;
			byte[] q = new byte[2000];
			q = a.toByteArray();
			for(int i=0;i<q.length;i++) p[0][i] = q[q.length-i-1];
			q = x.toByteArray();
			for(int i=0;i<q.length;i++) p[1][i] = q[q.length-i-1];
			q = b.toByteArray();
			for(int i=0;i<q.length;i++) p[2][i] = q[q.length-i-1];
			q = y.toByteArray();
			for(int i=0;i<q.length;i++) p[3][i] = q[q.length-i-1];
			
			for(int i=0;i<4;i++){
				for(int j=0;j<32;j++)
					System.out.print(get(j,i));
					System.out.println();
			}			
			boolean flag=false;
			for(int i=0;i<n;i++){
				boolean tmp = true;
				for(int j=0;j<n;j++){
					if(get(j,1)==get(j,3)){
						if(get((j+i)%n,0) != get((j+i)%n,2)) tmp=false;
					}else{
						if(get((j+i)%n,0) == get((j+i)%n,2)) tmp=false;
					}
				}
				if(tmp){
					flag = true;
					break;
				}
			}
			System.out.print("Case "+cas+": ");
			if(flag) System.out.println("Yes");
			else System.out.println("No");
		}
	}
	public static int get(int l,int x){
		int a = l>>3;
		int b = l&7;
		return (p[x][a]>>b)&1;
	}
}

