import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for(int cas = 0; cas < T; cas++) {
            int n = scanner.nextInt();
            BigInteger x = BigInteger.ONE;
            BigInteger y = BigInteger.valueOf(2);
            for(int i = 0; i < n; i++) {
                x = x.multiply(y);
            }
            System.out.println(x);
        }


    }
}
