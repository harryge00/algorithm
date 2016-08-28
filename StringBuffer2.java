public class StringBuffer2 {

    public static void main(String[] args) {
        StringBuffer a = new StringBuffer("Hello");
        StringBuffer b = new StringBuffer("World");
        
        // Append the string representation of the argument to the end of the buffer.
        // In this example we use a string, but the method also accepts int, float,
        // double, boolean, char (or char[]), as well as objects.
        operator(a,b);

        System.out.println(a+","+b);
        String stra = "hello", strb="world";
        operator(stra,strb);

        System.out.println(stra+","+strb);

        
    }
    private static void operator(StringBuffer a, StringBuffer b) {
        a.append(b);
        b=a;
        System.out.println("In operator: "+a+","+b);
    }
    private static void operator(String a, String b) {
        System.out.println((int)a);
        a+=b;
        System.out.println((int)a);
        b=a;
        System.out.println("In operator str: "+a+","+b);
    }

    private static void compareTime() {
        long startTime;
        String str = "";
        StringBuffer buffer = new StringBuffer();
        
        // Using String
        startTime = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) {
            str += "extra";
        }
        System.out.println("Time using String: "
                + (System.currentTimeMillis() - startTime) + " ms.");
        
        // Using StringBuffer
        startTime = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) {
            buffer.append("extra");
        }
        System.out.println("Time using StringBuffer: "
                + (System.currentTimeMillis() - startTime) + " ms.");
    }
}
