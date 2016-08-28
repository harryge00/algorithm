
import java.io.*;
import java.util.*;
public class hello
{
    public static boolean wordBreak(String s, Set<String> wordDict) {
        int curr = s.length();
        while(curr > 0) {
            boolean flag = false;
            for(String word : wordDict) {
                if(word.length() > curr )
                    continue;
                else if(s.substring(curr-word.length(),curr).equals(word))
                {
                    System.out.println(curr + word);
                    curr -= word.length();
                    flag = true;
                    break;
                }
            }
            if(flag ==false)
            return false;
        }
        return true;
        
    }
    public static void main(String args[])
    {
        String a = "aaaaaaa";
        Set<String> w = new HashSet<String> ();
        w.add("aaaa");
        w.add("aaa");
        System.out.println(wordBreak(a, w));
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
/*
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
*/
