
/*
 * import java.io.*;
import java.util.*;
public class hello
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int num;
        String str;
        num = cin.nextInt();
        for(int i = 0; i < num; i++) {
            str = cin.next();
            int count = 0;
            for(int j = 0; j < str.length(); j++) {
                if(str.charAt(j) <= '9' && str.charAt(j) >= '0')
                    count++;
            }
            System.out.println(count);
        }
    }
}
*/
import java.io.*;
import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int num;
        int n;
        num = cin.nextInt();
        for(int i = 0; i < num; i++) {
            n = cin.nextInt();
            System.out.printf("%.2f\n", calN(n));
            System.out.println();
        }
    }
    public static double calN(int n) {
        double res = 0;
        for(int i = 1; i<=n; i++) {
            double k = 1.0/i;
            if(i % 2 == 0)
                k = -k;
            res += k;
        }
        return res;
    }
}

