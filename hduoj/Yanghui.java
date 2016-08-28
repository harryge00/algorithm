
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
public class Yanghui
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int num;
        int n;
        while(cin.hasNextInt()) {
            n = cin.nextInt();
            int [] arr = {1};
            for(int i = 0; i < n; i++) {
                int [] arr2 = new int[i+1];
                arr2[0] = 1;
                if(i != 0)
                    System.out.printf("%d ", 1);
                //begin print
                for(int j = 1; j < i; j++) {
                    System.out.printf("%d ", arr[j-1] + arr[j]);
                    arr2[j] = arr[j-1] + arr[j];
                }
                arr2[i] = 1;
                System.out.println(1);
                arr = arr2;
            }
            System.out.println();
        }
    }
    }

