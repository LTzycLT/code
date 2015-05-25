import java.io.*;
import java.util.*;
import java.math.*;
public class b {
    
    public static void main(String args[])
    {
        int T;
        int iCase = 0;
        int n;
        BigInteger A,X,B,Y;
        int []a = new int[1010];
        int []x = new int[1010];
        int []b = new int[1010];
        int []y = new int[1010];
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        while(T > 0)
        {
            iCase++;
            n = cin.nextInt();
            A = cin.nextBigInteger();
            X = cin.nextBigInteger();
            B = cin.nextBigInteger();
            Y = cin.nextBigInteger();
            A = A.subtract(BigInteger.ONE);
            X = X.subtract(BigInteger.ONE);
            B = B.subtract(BigInteger.ONE);
            Y = Y.subtract(BigInteger.ONE);
            for(int i = 0;i < n;i++)
            {
                a[i] = A.mod(BigInteger.valueOf(2)).intValue();
                b[i] = B.mod(BigInteger.valueOf(2)).intValue();
                x[i] = X.mod(BigInteger.valueOf(2)).intValue();
                y[i] = Y.mod(BigInteger.valueOf(2)).intValue();
                A = A.divide(BigInteger.valueOf(2));
                B = B.divide(BigInteger.valueOf(2));
                X = X.divide(BigInteger.valueOf(2));
                Y = Y.divide(BigInteger.valueOf(2));
                //System.out.println(a[i]+" "+ x[i]+" "+ b[i]+" "+y[i]);
            }
            boolean flag = false;
            for(int k = 0;k <= n;k++)
            {
                x[n] = x[0];
                for(int i = 0;i < n;i++)x[i] = x[i+1];
                y[n] = y[0];
                for(int i = 0;i < n;i++)y[i] = y[i+1];
                boolean ff = true;
                for(int i = 0;i < n;i++)
                    if((x[i]^a[i]) != (y[i]^b[i]))
                    {
                        ff = false;
                        break;
                    }
                if(ff)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)System.out.println("Case "+iCase+": Yes");
            else System.out.println("Case "+iCase+": No");
            T--;
        }
    }

}
