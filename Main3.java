import java.util.*;
public class Main3
{
        private static final String [][] num= { 
            {" ",  "   ", " - ",  " - ",  "   ",  " - ", " - ", " - ",  " - ", " - "}, 
            {" ",  "  |", "  |",  "  |",  "| |",  "|  ", "|  ", "  |",  "| |", "| |"},
            {"*",  "   ", " - ",  " - ",  " - ",  " - ", " - ", "   ",  " - ", " - "},
            {" ",  "  |", "|  ",  "  |",  "  |",  "  |", "| |", "  |",  "| |", "  |"},
            {" ",  "   ", " - ",  " - ",  "   ",  " - ", " - ", "   ",  " - ", " - "}
        };
            
	public static void main(String args[])
	{
		Scanner reader=new Scanner(System.in);
        while(reader.hasNextInt()) {
            printRes(reader.nextInt());
        }
    }
    public static int nextPrime(int n) {
        if(n < 2)
            return 2;
        for(int i = n+1; ;i++) {
            boolean found = true;
            for(int j = 2; j < i/2; j++) {
                if(i % j == 0){
                    found = false;
                    break;
                }
            }
            if(found)
                return i;
        }
    }
    public static void printRes(int num) {
        List<Integer> list = new ArrayList<Integer>();
        int prime = 2;
        while(num > 1) {
            if(num % prime ==0)
            {
                list.add(prime);
                num /= prime;
                if(num > 1)
                    list.add(0);
            }
            else
                prime = nextPrime(prime);
        }
        for(int i = 0; i<5;i++) {
            for(int n : list) {
               printPrime(n, i); 
            }
            System.out.println();
        }

    }
    public static void printPrime(int n, int line) {
        if(n > 9)
            printPrime(n/10, line);
        System.out.print(num[line][n%10]);
    }
        
}
	
