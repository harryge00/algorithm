public class StringEquals {

    public static void main(String[] args) {
        String str1, str2, str3, str4;
        str1 = new String("hello world");
        str2 = "hello world";
        str3 = "hello world";
        str4 = new String(str1);
        
        System.out.println(str1.equals(str2));
        System.out.println(str3 == str2);
        System.out.println(str1.equals(str4));
        System.out.println(str1 ==str4);

        
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
