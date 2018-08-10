import java.util.Vector;
import java.util.Random;

public class MemoryEater
{
  public static void main(String[] args)
  {
    Random rand = new Random();

    int  delay = rand.nextInt(900) + 100;
    System.out.println( "delay " + delay );
    Vector v = new Vector();
    while (true)
    {
      byte b[] = new byte[1048500];
      v.add(b);
      try        
      {
          Thread.sleep(delay);
      } 
      catch(InterruptedException ex) 
      {
          Thread.currentThread().interrupt();
      }
      Runtime rt = Runtime.getRuntime();
      System.out.println( "free memory: " + rt.freeMemory() );
    }
  }
}
