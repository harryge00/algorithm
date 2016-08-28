
import java.util.Scanner;
public class Main
{
	public static void main(String args[])
	{
		int m,n,a,b;
		Scanner reader=new Scanner(System.in);
        int lines = reader.nextInt();
        for(int i = 0; i < lines; i++) {
            int total = 0;
            boolean failed = false;
            for(int j = 0; j < 4; j++) {
                int score = reader.nextInt();
                if(j<2 && score < 60)
                {
                    failed = true;
                    break;
                }
                else if(j>1 && score < 90) {
                    failed = true;
                    break;
                }
                total += score;
            }
            while(reader.hasNext())
                reader.next();

            if(failed || total <310)
                System.out.println("Fail");
            else {
                if(total>=350)
                    System.out.println("Gongfei");
                else
                    System.out.println("Zifei");
            }
        }
    }
}
	
