import java.io.*;
import java.util.*;
public class CCI3_6
{
    public static Stack<Integer> sort(Stack<Integer> s)
    {
        
        Stack<Integer> r = new Stack<Integer>();
        int tmp;
        r.push(s.pop());
        while(!s.isEmpty()) {
            if(r.peek() >= s.peek())
                r.push(s.pop());
            else
            {
                tmp = s.pop();
                while(!r.isEmpty()) {
                    s.push(r.pop());
                }
                r.push(tmp);
            }
        }
        while(!r.isEmpty()){
            System.out.println(r.peek());
            s.push(r.pop());
        }
        return s;
    }
    
    public static void main(String args[])
    {
        Stack<Integer> original = new Stack<Integer>();
        original.push(3);
        original.push(7);
        original.push(8);
        original.push(1);
        original.push(4);
        original.push(0);
        original.push(5);
        original.push(1);
        sort(original);
    }
}
