 
import java.util.HashMap;
 
 
public class Code {
 
           
            private final int id;
 
            public int getId() {
                        return id;
            }
 
           
            public Code(int id) {
                        this.id = id;
            }
 
           
            public boolean equals(Object o) {
                        // 如果地址一样，则两个对象相同
                        if (this == o) {
                                     return true;
                        }
                        // 如果两个对象是同一类型，则比较其属性值是否都相同。如果都相同，则说明两个对象也相同；否则，说明这两个对象不相同。
                        if (o instanceof Code) {
                                     Code co = (Code) o;
                                     boolean b = (co.id == this.id);
                                     return b;
                        }
                        return false;
            }
 
           
            public String toString() {
                        return "【身份证】：" + id;
            }
           
           
            public static void main(String[] args) {
                       
                         HashMap<Code, Person> map = new HashMap<Code, Person>();
                         
                         Person p1 = new Person(new Code(10001),"张三");
                         Person p2 = new Person(new Code(10002),"李四");
                         
                         map.put(p1.getCode(), p1);
                         map.put(p2.getCode(), p2);
                         
                         System.out.println("HashMap 中存放的人员信息:\n"+map);
                         
                         //张三改名为张山，身份证号不变。
                         Person p3 = new Person(new Code(10001),"张山");
                         map.put(p3.getCode(), p3);
                         
                         System.out.println("张三改名为张山后 HashMap 中存放的人员信息:\n"+map);
                         
                         //查找身份证为10001 的人员信息
                         System.out.println("查找身份证为：10001 的人员信息:"+map.get(new Code(10001)));
            }
}
 
 
class Person {
 
           
            private Code code;
 
           
            private String name;
 
            public Code getCode() {
                        return code;
            }
 
            public void setCode(Code code) {
                        this.code = code;
            }
 
            public String getName() {
                        return name;
            }
 
            public void setName(String name) {
                        this.name = name;
            }
 
            public Person() {
 
            }
 
            public Person(Code code, String name) {
                        this.code = code;
                        this.name = name;
            }
 
           
            public boolean equals(Object o) {
                        if (o == this) {
                                     return true;
                        }
                        if (o instanceof Person) {
                                     Person p = (Person) o;
                                     boolean b = this.code.equals(p.code) && this.name.equals(p.name);
                                     return b;
                        }
                        return false;
            }
 
           
            public String toString() {
                        return "【姓名】：" + name + "  ";
            }
}