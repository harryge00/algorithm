
import java.io.*;
import java.util.*;
public class test
{
    private static void print(int []a) {
        System.out.println(a[1]);
    }
    public static void main(String args[])
    {
       int []s = null;
       print(s);
    }
}
/*
import java.io.*;
import java.util.*;
*/
class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int num;
        int n;
        num = cin.nextInt();
        for(int i = 0; i < num; i++) {
            n = cin.nextInt();
            System.out.println(calN(n));
        }
    }
    public static double calN(int n) {
        double res = 0;
        for(int i = 1; i<=n; i++) {
            double k = 1.0/i;
            if(k % 2 == 0)
                k = -k;
            res += k;
        }
        return res;
    }
}

