import java.util.Random;

public class data{
	static Random p = new Random();
	static int rand0(int x){
		return p.nextInt(x);
	}
	static int rand1(int x){
		return p.nextInt(x)+1;
	}
	public static void main(String args[]){
		int n = rand1(30);
		int a = rand1(1<<n);
		int x = rand1(1<<n);
		int b = rand1(1<<n);
		int y = rand1(1<<n);
		System.out.println(1);
		System.out.println(n+" "+a+" "+x+" "+b+" "+y);
	}
}

