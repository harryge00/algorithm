import java.io.*;
import java.util.*;
import org.junit.Test;
import static org.junit.Assert.*;
public class CCI1_8
{
    public static boolean isSubstring(String a, String b)
    {
        if(b == null)
            return false;
        if(a == null)
            return true;
        int len = a.length();
        for(int i = 0; i+len <= b.length(); i++){
            System.out.println(b.substring(i, i+len));
            if(b.substring(i,i+len).equals(a))
                return true;
        }
        return false;
    }
    public static boolean isRotation(String a, String b) {
        if(a == null || b == null)
            return false;
        if(a.length() != b.length())
            return false;
        for(int i = 1; i < b.length() -1; i++) {
            if(isSubstring(a.substring(0,i), b) && isSubstring(a.substring(i,a.length()), b))
                return true;
        }
        return false;
    }
    public static void main(String args[])
    {
        String patter = "apple";
		String test1 = "pleap";
		String test2 = "plepa";
        System.out.println(isRotation(patter, test1));
        System.out.println(isRotation(patter, test2));
    }
}
