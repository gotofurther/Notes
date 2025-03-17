# ***Java***

------

### ***static***

*称为静态，可以修饰修饰成员变量和成员方法*

1. **static**修饰成员变量/方法：  
   成员变量/方法按有无**static**修饰，分为两种：
    * 类变量/方法：有**static**修饰，属于类，在计算机中只有一份，会被全部对象共享
    * 实例变量/方法(对象的变量/方法)：无**static**修饰，属于每一个对象

   **对于类变量/方法的访问：**

        类名.类变量/方法(推荐)  
        对象.类变量/方法(不推荐)
   **对于实例变量/方法的访问：**

        对象.实例变量/方法

   **应用场景：**

    * 类变量：在开发中，如果一个数据只要一份，且希望能够被共享，则该数据可以被定义成类变量来记住
    * 类方法：做工具类(工具类构造方法最好私有)

2. **注意事项：**

    * *类方法中可以直接访问类变量，不可以直接访问实例变量*
    * *实例方法既可以直接访问类变量，也可以访问实例变量*
    * *实例方法中可以出现**this**关键字，类方法中不可以出现**this**关键字*
3. **应用：**
    * 静态代码块：
        * 格式：**static{ }**
        * 特点：类加载时自动执行，由于类只会加载一次，所以静态代码块也只会执行一次
        * 作用：完成类的初始化，例如：对类变量的初始化赋值
    * 实例代码块：
        * 格式：**{ }**
        * 特点：每次创建对象时，执行实例代码块，并在构造函数前执行
        * 作用：和构造函数一样，都是用来完成对象的初始化，例如：对实例变量进行初始化赋值

------

### ***final***
*final关键字是最终的意思，可以修饰(类，方法，变量)*

* 修饰类：该类为最终类，不能被继承了
* 修饰方法：该方法被称为最终方法，不能被重写了
* 修饰变量：该变量只能赋值一次

注意：
* final修饰基本类型的变量，变量储存的数据不能被改变
* final修饰引用类型的变量，变量储存的地址不能被改变，但地址所指向对象的内容是可以改变的

------

### ***继承***

*子类(派生类)能继承父类(基类,超类)的非私有成员变量*

```java
public class A extends B {

}
//A为子类
//B为父类
```

1. 权限修饰符：

   |    修饰符    | 在本类中 | 同一个包下其他类中 | 任意包下的子类里 | 任意包下的任意类里 |
   |:---------:|:----:|:---------:|:--------:|:---------:|
   |  private  |  √   |           |          |           |
   |   无修饰符    |  √   |     √     |          |           |
   | protected |  √   |     √     |    √     |           |
   |  public   |  √   |     √     |    √     |     √     |
2. 方法重写：  
    * *当子类觉得父类中的某个方法不好用，或者无法满足自己的需求时，子类可以重写一个方法名称、参数列表一样的方法，去覆盖父类的这个方法，这就是方法重写*
    * *重写后，方法的访问**Java**会遵循就近原则*
    * 注意：
        * *使用**Override**注解可以检查重写格式是否正确，且代码可读性也会更好*
        * *子类重写父类方法时，访问权限必须大于或等于父类该方法的权限*
        * *重写的方法返回值类型必须与重写方法返回值类型一样，或者范围更小*
        * *私有方法、静态方法不能重写，如果重写会报错*
3. 子类访问成员变量的特点：
    * *子类中访问其他成员(成员方法、成员变量)，是依照就近原则的*
    * *若要访问父类成员，则应加上**super**前缀*
      ```
      super.XXX
      super.function()
      ```
4. 子类构造函数的特点：  

    * *子类的全部构造函数，都会先调用父类的构造函数，再执行自己，因为子类继承父类，子类构造函数先调用父类构造函数实现把对象父类这部分的数据先初始化，再回来把对象里包含子类的这部分初始化*
    * *默认情况下，子类全部构造函数的第一行代码都是**super( )**( 写不写都有 )，他会调用父类函数的无参构造函数*
    * *若父类没有无参构造函数,则必须在子类构造函数的第一行手写 **super( )**，去调用父类的指定构造函数*
    * 补充：
        * *在任意构造函数中，是可以通过this(…)去调用其他构造函数，但是有了this(…)就不能再有super(…)
          ，this.与super.应该不冲突*

------

### ***多态***
   *多态是在继承/实现情况下的一种现象，表现为对象多态、行为多态*  
1. 前提：  
   * 有继承/实现关系：
      ```java
      public class People{}
      public class Student extends People{}
      ```
   * 存在父类引用子类对象
      ```java
      People p = new Student();
      ```
   * 存在方法重写：

2. 对象多态：
   ```java
    //例如
    People p1 = new Student();
    People p2 = new Teacher();
   ```
   行为多态：*子类重写父类方法*
3. 注意事项：
   *多态是对象、行为的多态，**Java**中的属性(成员变量)不谈多态*  
   *即：对于方法编译看左边，运行看右边，对于变量编译看左边，运行看左边*
4. 利弊：
   * [x] *可以解耦合，扩展性更强*
   * [x] *使用父类型变量作为方法的形参时，可以接受一切子类对象*
   * [ ] *多态下不能调用子类独有方法( 如果需要调用子类方法需要强制类型转换 )*

------
### 抽象类  
***abstract**修饰的类为抽象类，**abstract**修饰的方法称为抽象方法*  
特点：
* 抽象类中不一定有抽象方法，有抽象方法的类一定是抽象类
* 类有的成员(成员变量，方法，构造器)抽象类都可以有
* **主要特点**：抽象类不能创建对象，仅作为一种特殊的父类，让子类继承实现
* 一个类继承抽象类，必须重写抽象类的全部抽象方法，否则这个类也必须定义为抽象类  

使用场景与好处：  
*父类知道每一个子类都要做某一个行为，但每一个子类要做的情况不一样，父类就定义抽象类方法，交给子类去重写实现，通过设计这样的抽象类，可以更好的支持**多态***

常见应用场景——模板方法设计模式：  
*对于多个类有大部分重复代码*
1. 定义一个抽象类
2. 在里面定义两个方法  
    * 一个是模板方法(*最好加**final**修饰以防止子类重写*)：把相同代码放里面
    * 一个是抽象方法：具体实现交给子类完成

------
### 接口
*通过**interface**关键字我们可以定义一个特殊结构——接口*  
特点：(仅有常量与抽象方法)
* 成员变量为常量(***public static final***)(常量的命名最好大小如**SCHOOL_NAME**)
* 成员方法为抽象方法(***public abstract***)
* 接口不能创建对象，而是用来被实现的，实现接口的类称为实现类
* **一个类可以实现多个接口，实现类实现(*implements*)多个接口，必须重写全部接口的全部抽象方法，否则需要定义成抽象类，若实现的多个接口中存在接口方法名相同，则无法多实现**
* 一个接口可以**继承**多个接口,注意是**extends**而非**implements**，若多个接口方法名冲突，则无法继承  

优点：
* 弥补了类单继承的不足，一个类可以实现多个接口
* 让程序可以面向接口编程，可以灵活方便切换各种业务实现

**JDK8**后接口新增功能(*增加接口能力，便于开发与维护*)：
1. 默认方法(实例方法)：使用**default**修饰，默认加上**public**，只能使用接口的实现类对象调用
2. 类方法(静态方法)：使用**static**修饰，默认加上**public**只能用接口名来调用
3. 私有方法：**JDL9**之后才支持，必须用**private**修饰

注：  
* *若一个类继承了父类，同时实现了接口，且父类与接口中有同名的默认方法，则优先用父类的*  
* *一个类实现了多个接口，多个接口中存在同名的默认方法，可以不冲突，这个类重写该方法即可*
------
### 内部类
*可以极大的简化代码*
* *一个类定义在另一个类的内部*
* *当一个类的内部包含了一个完整事物，且这个事物没有必要单独设计时，就可以把这个事物设计成内部类*  
种类：
1. 成员内部类  
   *(就是类中的一个普通的成员，类似于前面的成员方法，成员方法)*
   * 创建对象的格式：
     ```java
     //外部类名.内部类名 对象名 = new 外部类(……).new 内部类(……);
     Outer.Inner in = new Outer().new Inner();
     ```
2. 静态内部类  
   *(有**static**修饰的内部类，属于外部类自己特有)*
   * 创建格式同上
   * 可以直接访问外部类的静态成员，不可以直接访问外部类的实例成员
3. **匿名内部类**  
*(一种特殊的局部内部类，所谓匿名：指的是程序员不需要为这个类声明名字)*  

   * 书写格式：
   ```
   new 类或接口(参数值……){  
      类体(一般是方法重写);   
   }
   ```     
   * 特点：  
   *本质就是一个子类，并且会立即创建出一个子类对象*
   * 作用与应用场景：
     * *可以更方便的创建出一个子类对象*
     * *匿名内部类通常作为一个参数直接传给方法(一般是对于别人给定的方法中需要传类对象时才使用，其核心目的是**简化代码**)*
------
### 枚举类
*枚举是一种特殊格式，可以很好的限定语义，能够在编译阶段就检查每个值的合理性*  
1. 格式：
   ```
   修饰符 enum 枚举类名{
      名称1，名称2……;
      (其他成员)
   }
   ```

2. 特点：

   * *枚举类中的第一行只能罗列名称，这些名称都是常量，并且每个常量记住的都是枚举类的一个对象*
   * *枚举类的构造器都是私有的(写与不写都只能是私有的)，因此，枚举类对外不可创建对象*
   * *枚举类是最终类，不可被继承*
   * *枚举类中从第二行开始可以定义类的其他各种成员*
   * *编译器为枚举类新增了几个方法，并且枚举类都是继承：**java.lang.Enum**类的，从Enum类也会继承到一些方法*

3. 常见应用场景：
   * *用来表示一组信息，让后作为参数进行传输(选择定义一个一个常量来表示一组信息，并作为参数传输)*
   * *参数值不受约束(选择定义枚举表示一组信息，并作为参数传递)*
   * *代码可读性好，参数值得到了约束*

4. 使用案例：
   ```java
   public enum Constant{
       BOY,GIRL
   }
   ```
   ```java
   public static void check(Constant sex){
        switch(sex){
            case BOY:
                System.out.println("Boy");
                break;
            case GIRL:
                System.out.println("Girl");
                break;
        }
   }
   ```
------
### 泛型
*定义类、接口、方法时，同时声明了一个或者多个类型变量(如：<E>)，称为泛型类、泛型接口、泛型方法，它们统称为泛型*
1. 作用：   
   * *泛型提供了在编译阶段约束所能操作的数据类型，并自动进行检查的能力，这样可以避免强制类型转换，及其可能出现的异常*  
   * ***其本质为把具体的数据类型作为参数传给类型变量***
2. 泛型类：
   * 格式：
      ```
      修饰符 class 类名<变量类型,变量类型,……>{
   
      }
      ```
   * 例如：
      ```
      public class MyArrayList<E>{
      private Object[] arr = new Object[10];
   
      private int size;
         public boolean add(E e){
         arr[size++] = e;
         }
      }
   
      public E get(int index){
         return (E) arr[index]; 
      }
   
      //--------------------------------------
   
      public class MyClass<E, T>{
          public void put(E e, T t){
       
          } 
      }
   
      //--------------------------------------
   
      public class MyClass<E extends Animal>{
          public void put(E e){
       
          } 
      }
      ```
     
3. 泛型接口
   * 格式：
   ```
   修饰符 interface 接口名<类型变量,变量类型,……>{
   
   }
   ```
   * 常例同泛型类

4. 泛型方法
   * 格式：
      ```
      修饰符<类型变量,变量类型,……> 返回值类型 方法名(形参列表){
   
      }
      ```
   * 例如：
      ```java
      public static <T> void test(T t){
   
      }
     //----------------------------------------------
     public static <T extends Cars> void go(ArrayList<T> cars){
     
     }
      ```
   * 通配符(?)：在使用泛型的时候可以代表一切类型
      * 例如：
         ```java
         public static void go(ArrayList<?> cars){
         
         }
         
         //------------------------------------------------
         public static void go(ArrayList<? extends Cars> cars){
     
         }
         ```
      * 上下限：
        * 泛型上限： ? extends Cars：?能接受的必须是Cars或其子类 
        * 泛型下限： ? super Cars：?能接受的必须是Cars或其父类 
   
------
### 常用API
*API(Application Programming Interface)：应用程序接口*

#### Object类
*Object类是Java中所有类的祖宗类，因此，Java中所有类的对象都可以直接使用Object类中提供的一些方法*
* Object类常用方法：

   | 方法名                             |        说明        |
   |:--------------------------------|:----------------:|
   | public String toString()        |   返回对象的字符串表现形式   |
   | public boolean equals(Object o) | 判断两个对象(默认地址)是否相等 |
   | protected Object clone()        |       对象克隆       |

#### Objects类
*Objects类是一个工具类，提供了很多操作对象的静态方法*
* Objects类常用方法：

  | 方法名                                              |                 说明                 |
  |:-------------------------------------------------|:----------------------------------:|
  | public static boolean equals(Object a, Object b) |           先做非空判断，再比较两个对象           |
  | public static boolean isNull(Object obj)         |  判断对象是否为null，为null返回true，反之为false  |
  | public static boolean nonNull(Object obj)        | 判断对象是否不为null，不为null返回true，反之为false |

#### 包装类
*包装类就是把基本类型的数据包装成对象*
* 包装类列举： 

   | 基本数据类型   | 对应包装类(引用数据类型) |
   |----------|---------------|
   | byte     | Byte          |
   | short    | Short         |
   | **int**  | **Integer**   |
   | long     | Long          |
   | **char** | Character     |
   | float    | Float         |
   | double   | Double        |
   | boolean  | Boolean       |

* 包装类与基本数据类型的转换：
   * 包装类内部自带方法：例如Integer自带的valueOf()等
      ```
     Integer a = Integer.valueOf(12);
      ```
   * 自动装箱：
      ```
      Integer a1 = 12;
      ```
   * 自动拆箱：
      ```
      int a2 = a1;
      ```
     
* 包装类的其他常见操作：
   * 可以把基本类型的数据转换成字符串类型：
      > public static String toString(double d)
      > public String toSting()
   * 可以把字符串类型的数值转换成数值本身对应的字符类型：
      > public static int parseInt(String s)
      > public static Integer valueOf(String s)
 

#### StringBuilder
*StringBuilder代表可变字符串对象，相当于是一个容器，它里面装的字符串是可以改变的，就是用来操作字符串的*  
*支持链式编程*
* 常用方法：

   | 构造器                              | 说明                      |
   |----------------------------------|-------------------------|
   | public StringBuilder()           | 创建一个空白的可变的字符串对象，不包含任何内容 |
   | public StringBuilder(String str) | 创建指定字符串内容的可变字符串对象       |
   
   | 方法名称                              | 说明                                       |
   |-----------------------------------|------------------------------------------|
   | public StringBuilder append(任意类型) | 添加数据并返回StringBuilder对象本身                 |
   | public StringBuilder reverse()    | 将对象内容反转                                  |
   | public int length()               | 返回对象内容长度                                 |
   | public String toString()          | 通过toString()就可以实现把StringBuilder转换为String |

* String与StringBuilder的选择：
  * 对于字符串相关的操作，如频繁的拼接、修改等，建议用StringBuilder，效率更高
  * 若字符串较少，或者不需要操作，以及定义字符串变量，还是建议用String
* StringBuffer与StringBuilder的区别：
   * StringBuffer的用法与StringBuilder是一模一样的
   * 但StringBuilder是线程不安全的，StringBuffer是线程安全的
* StringJoiner(JDK8后才有)：
   *与StringBuilder一样，也是用来操作字符串的，也可以看成是一个容器，创建之后里面的内容是可变的*
   *可以提升字符串操作效率，并且在有些场景下使用它操作字符串代码会更简洁*
   * 常用方法：
  
   | 构造器                                 | 说明                                      |
   |-------------------------------------|-----------------------------------------|
   | public StringJoiner(间隔符号)           | 创建一个StringJoiner对象，指定拼接时的间隔符号           |
   | public StringJoiner(间隔符号,开始符号,结束符号) | 创建一个StringJoiner对象，指定拼接时的间隔符号，开始符号，结束符号 |

  | 方法名称                           | 说明                    |
  |--------------------------------|-----------------------|
  | public StringJoiner add(添加的内容) | 添加数据，并返回对象本身          |
  | public int length()            | 返回长度(字符串出现个数)         |
  | public String toString()       | 返回一个字符串(该字符串就是拼接后的结果) |

#### Math
*代表数学，是一个工具类，里面提供的都是对数据进行操作的一些静态方法*
* 常见方法：
    
    | 方法名                                         | 说明                         |
    |---------------------------------------------|----------------------------|
    | public static int abs(int a)                | 获取参数绝对值                    |
    | public static double ceil(double a)         | 向上取整                       |
    | public static double floor(double a)        | 向下取整                       |
    | public static int round(float a)            | 四舍五入                       |
    | public static int max(int a,int b)          | 获取两个int值中的较大值              |
    | public static double pow(double a,double b) | 返回a的b次幂                    |
    | public static double random()               | 返回值为double的随机值，范围[0.0,1.0) |

#### System
*System代表程序所在的系统，也是一个工具类*
* 常见方法：

    | 方法名                                    | 说明                                            |
    |----------------------------------------|-----------------------------------------------|
    | public static void exit(int status)    | 终止当前运行的虚拟机                                    |
    | public static long currentTimeMillis() | 返回当前系统的时间毫秒值形式(指的是从1970-1-1 0:0:0开始走到此刻的总毫秒值) |

#### Runtime
*代表程序所在的运行环境，Runtime是一个单例类*
* 常见方法：

    | 方法名                                 | 说明                    |
    |-------------------------------------|-----------------------|
    | public static Runtime getRuntime()  | 返回与当前Java应用程序关联的运行时对象 |
    | public void exit(int status)        | 终止当前运行的虚拟机            |
    | public int availableProcessors()    | 返回Java虚拟机可用的处理器数      |
    | public long totalMemory()           | 返回Java虚拟机中的内存总量       |
    | public long freeMemory()            | 返回Java虚拟机中的可用内存       |
    | public Process exec(String command) | 启动某个程序，并返回代表该程序的对象    |

#### BigDecimal
*用于解决浮点型运算时，出现结果失真的问题*
 常用方法：

   | 构造器                           | 说明                       |
   |-------------------------------|--------------------------|
   | public BigDecimal(double val) | 将double转为BigDecimal(不推荐) |
   | public BigDecimal(String val) | 将String转为BigDecimal      |

   | 方法名                                                 | 说明                    |
   |-----------------------------------------------------|-----------------------|
   | public static BigDecimal valueOf(double val)        | 转换一个double成BigDecimal |
   | public BigDecimal add(BigDecimal b)                 | 加法                    |
   | public BigDecimal subtract(BigDecimal b)            | 减法                    |
   | public BigDecimal multiply(BigDecimal b)            | 乘法                    |
   | public BigDecimal divide(BigDecimal b)              | 除法                    |
   | public BigDecimal divide(另一个BigDecimal对象，精确几位，舍入模式) | 除法、可以控制精确到几位小数        |
   | public double doubleValue()                         | 将BigDecimal转换成double  |

#### Date(传统)
*代表的是日期与时间*
* 常见构造器与方法：

    | 构造器                    | 说明                      |
    |------------------------|-------------------------|
    | public Date()          | 创建一个Date对象，代表的是系统此刻日期时间 |
    | public Date(long time) | 把时间毫秒值转成Date日期对象        |

    | 常见方法                           | 说明                           |
    |--------------------------------|------------------------------|
    | public long getTime()          | 返回从1970年1月1日 0:0:0走到此刻的总的毫秒数 |
    | public void setTime(long time) | 设置日期对象的时间为当前时间毫秒值对应的时间       |
    
#### SimpleDateFormat(传统)
*代表简单日期格式化，可以用来把日期对象、时间毫秒值格式化成我们想要的形式*

* 常见构造器及方法：
    
   | 构造器                                     | 说明                                                       |
   |-----------------------------------------|----------------------------------------------------------|
   | public SimpleDateFormat(String pattern) | 创建简单日期格式化对象，并封装时间的格式(如yyyy年MM月dd日 HH：mm：ss EEE a等要求查看文档) |

   | 方法                                      | 说明               |
   |-----------------------------------------|------------------|
   | public final String format(Date date)   | 将日期格式化成日期/时间字符串  |
   | public final String format(Object time) | 将时间毫秒值化成日期/时间字符串 |
   | public Date parse(String source)        | 把字符串时间解析成日期对象    |

* 时间格式常见符号：

    | 常见符号 | 对应内容  |
    |------|-------|
    | y    | 年     |
    | M    | 月     |
    | d    | 日     |
    | H    | 时     |
    | m    | 分     |
    | s    | 秒     |
    | EEE  | 星期几   |
    | a    | 上午/下午 |

#### Calendar(传统)
*代表系统此刻时间对应的日历，通过它可以单独获取、修改时间中的年、月、日、时、分、秒等*

* 常见方法：

    | 方法名                                    | 说明                     |
    |----------------------------------------|------------------------|
    | public static Calendar getInstance()   | 获得当前日历对象               |
    | public int get(int field)              | 获取日历中的某个信息(如YEAR等静态常量) |
    | public final Date getTime()            | 获取日期对象                 |
    | public long getTimeInMillis()          | 获取时间毫秒值                |
    | public void set(int field, int value)  | 修改日历的某个信息              |
    | public void add(int field, int amount) | 为某个信息增加/减少指定的值         |

* 注意：
    calendar是可变对象，一旦修改后其对象本身表示的时间将发生变化

#### JDK8后新增时间API
*JDK8后新增设计更为合理，功能更加丰富，使用更加方便，且为不可变对象，线程安全，可精确到纳秒的API(若非一定要用传统时间API则建议使用新增的)*

* 代替Calendar：
  * LocalDate：年、月、日、星期
    >常用方法：

      | 方法名                                                      | 说明                           | 示例                                            |
      |----------------------------------------------------------|------------------------------|-----------------------------------------------|
      | public static LocalDate now()                            | 获取系统当前时间(年、月、日)对应的该对象(不可变对象) | LocalDate ld = LocalDate.now();               |
      | public static LocalDate of(int year, int month, int day) | 获取指定日期的LocalDate对象           | LocalDate LD = LocalDate.of(2304,5,3)         |
      | getYear()                                                | 获取年                          | int year = ld.getYear();                      |
      | getMonthValue()                                          | 获取月                          | int month = ld.getMonthValue();               |
      | getDayOfMonth()                                          | 获取日                          | int day = ld.getDayOfMonth();                 |
      | getDayOfYear()                                           | 获取一年中的第几天                    | int dayOfYear = ld.getDayOfYear();            |
      | getDayOfWeek().getValue();                               | 星期几                          | int dayOfWeek = ld.getDayOfWeek().getValue(); |
      | withYear(int Year)                                       | 直接修改年                        | LocalDate ld2 = ld.withYear(2304);            |
      | withMonth(int Month)                                     | 直接修改月                        | LocalDate ld3 = ld.withMonth(5);              |
      | withDayOfMonth(int Day)                                  | 直接修改日                        | LocalDate ld4 = ld.withDayOfMonth(3);         |
      | withDayOfYear(int Day)                                   | 直接修改到一年中的第几天                 | LocalDate ld5 = ld.withDayOfYear(33);         |
      | plusYears(int Year)                                      | 把年增加多少                       | LocalDate ld6 = ld.plusYears(23045333);       |
      | plusMonths(int Month)                                    | 把月增加多少                       | LocalDate ld7 = ld.plusMonths(23045333);      |
      | plusDays(int Day)                                        | 把日增加多少                       | LocalDate ld8 = ld.plusDays(23045333);        |
      | plusWeeks(int Week)                                      | 把星期增加多少                      | LocalDate ld9 = ld.plusWeeks(23045333);       |
      | minusYears(int Year)                                     | 把年减少多少                       | LocalDate ld10 = ld.minusYears(23045333);     |
      | minusMonths(int Month)                                   | 把月减少多少                       | LocalDate ld11 = ld.minusMonths(23045333);    |
      | minusDays(int Day)                                       | 把日减少多少                       | LocalDate ld12 = ld.minusDays(23045333);      |
      | minusWeeks(int Week)                                     | 把星期减少多少                      | LocalDate ld13 = ld.minusWeeks(23045333);     |
      | equals(LocalDate ld)                                     | 判断日期是否相等                     | ld7.equals(ld6);                              |
      | isBefore(LocalDate ld)                                   | 判断日期是否在前                     | ld8.isBefore(ld7)                             |
      | isAfter(LocalDate ld)                                    | 判断日期是否在后                     | ld9.isAfter(ld8)                              |

  * LocalTime：时、分、秒、纳秒
    >常用方法(示例使用同上)：

      | 方法名                                                          | 说明                              |
      |--------------------------------------------------------------|---------------------------------|
      | public static LocalTime now()                                | 获取系统当前时间(时、分、秒、纳秒)对应的该对象(不可变对象) |  
      | public static LocalTime of(int hour, int minute, int second) | 获取指定日期的LocalTime对象              | 
      | getHour()                                                    | 获取小时                            | 
      | getMinute()                                                  | 获取分钟                            | 
      | getSecond()                                                  | 获取秒                             |
      | getNano()                                                    | 获取纳秒                            | 
      | withHour(int Hour)                                           | 直接修改时                           | 
      | withMinute(int Minute)                                       | 直接修改分                           |
      | withSecond(int Second)                                       | 直接修改秒                           | 
      | withNano(int Nano)                                           | 直接修改纳秒                          | 
      | plusHours(int Hour)                                          | 把时增加多少                          |
      | plusMinutes(int Minute)                                      | 把分增加多少                          |
      | plusSeconds(int Second)                                      | 把秒增加多少                          |
      | plusNanos(int Nano)                                          | 把纳秒增加多少                         | 
      | minusHours(int Hour)                                         | 把时减少多少                          |
      | minusMinutes(int Minute)                                     | 把分减少多少                          |
      | minusSeconds(int Second)                                     | 把秒减少多少                          | 
      | minusNanos(int Nano)                                         | 把纳秒减少多少                         | 
      | equals(LocalTime lt)                                         | 判断日间是否相等                        | 
      | isBefore(LocalTime lt)                                       | 判断日间是否在前                        |
      | isAfter(LocalTime lt)                                        | 判断日间是否在后                        | 

  * LocalDateTime：年、月、日、时、分、秒、纳秒
    > 常用方法(就是LocalDate与LocalTime方法总和，以上的LocalDateTime都可以使用)  
      注意(获取对象的方法不同)：
  
    | 方法名                                                                                                                     | 说明                                    |
    |-------------------------------------------------------------------------------------------------------------------------|---------------------------------------|
    | public static LocalDateTime of(int year, int Month, int dayOfMonth, int hour, int minute, int second, int nanoOfSecond) | 获取系统当前时间(年、月、日、时、分、秒、纳秒)对应的该对象(不可变对象) |
    | public LocalDate toLocalDate()                                                                                          | 把LocalDateTime转换成LocalDate            |
    | public LocalTime toLocalTime()                                                                                          | 把LocalDateTime转换成LocalTime            |
    | public static LocalDateTime of(LocalDate date, LocalTime time                                                           | 把LocalDate与LocalTime转换成LocalDateTime  |
  * ZoneId：时区
    >常用方法：
    
    | 方法名                                             | 说明             |
    |-------------------------------------------------|----------------|
    | public static Set<String> getAvailableZoneIds() | 获取Java中支持的所有时区 |
    | public static ZoneId systemDefault()            | 获取系统默认时区       |
    | public static ZoneId of(String zoneId)          | 获取一个指定时区       |
  * ZonedDateTime：带时区的时间
    >常用方法：

    | 方法名                                                                                               | 说明                     |
    |---------------------------------------------------------------------------------------------------|------------------------|
    | public static ZonedDateTime now()                                                                 | 获取当前时区的ZonedDateTime对象 |
    | public static ZonedDateTime now(ZoneId zone)                                                      | 获取指定时区的ZonedDateTime对象 |
    | getYear、getMonthValue、getDayOfMonth、getDayOfYear、getDayOfWeek、getHour、geyMinute、getSecond、getNano | 获取年月日、时分秒、纳秒           |
    | public ZonedDateTime withXxx(时间)                                                                  | 修改时间系列的方法              |
    | public ZonedDateTime minusXxx(时间)                                                                 | 减少时间系列的方法              |
    | public ZonedDateTime plusXxx(时间)                                                                  | 增加时间系列的方法              |
* 代替Date：
  * Instant：时间戳/时间线/时刻  
     *通过Instant的对象可以拿到此刻的时间，该时间由两部分组成：从1970-01-01 00:00:00开始走到此刻的总秒数+不够1秒的纳秒数*
    >常用方法：
  
     | 方法名                                  | 说明                             |
     |--------------------------------------|--------------------------------|
     | public static Instant now()          | 获取当前时间的Instant对象(标准时间)         |
     | public long getEpochSecond()         | 获取从1970-01-01 00:00:00开始记录的秒数  |
     | public int getNano()                 | 从时间线开始，获取从第二个开始的纳秒数            |
     | plusMillis plusSeconds plusNanos     | 增加时间系列方法                       |
     | minusMillis minusSeconds minusNanos  | 减少时间系列方法                       |
     | equals、isBefore、isAfter              | 判断时间系列方法                       |


* 代替SimpleDateFormat：
  * DateTimeFormatter：用于时间格式化和解析(线程安全)
    >常用方法：

      | 方法名                                                                               | 说明       |
      |-----------------------------------------------------------------------------------|----------|
      | public static DateTimeFormatter ofPattern(时间格式)                                   | 获取格式化器对象 |
      | public String format(时间对象)                                                        | 格式化时间    |
      | public String format(DateTimeFormatter formatter)                                 | 格式化时间    |
      | public static LocalDateTime parse(CharSequence text, DateTimeFormatter formatter) | 解析时间     |

* 其他补充：
   * Period：时间间隔(年、月、日)  
     *可以用于计算两个LocalDate对象相差的年数、月数、天数*
      > 常见方法：
    
      | 方法名                                                          | 说明                  |
      |--------------------------------------------------------------|---------------------|
      | public static Period between(LocalDate start, LocalDate end) | 传入两个日期对象，获得Period对象 |
      | public int getYears()                                        | 计算隔几年，并返回           |
      | public int getMonths()                                       | 计算隔几月，并返回           |
      | public int getDays()                                         | 计算隔几天，并返回           |
  
   * Duration：时间间隔(时、分、秒、纳秒)  
     *可以用于计算两个时间对象相差的天数、小时数、分数、秒数、纳秒数；支持LocalTime、LocalDAteTime、Instant等时间*
     > 常见方法：
      
      | 方法名                                             | 说明                    |
      |-------------------------------------------------|-----------------------|
      | public static Duration between(开始时间对象1,截止时间对象2) | 传入2个时间对象，得到Duration对象 |
      | public long toDays()                            | 计算间隔多少天，并返回           |
      | public long toHours()                           | 计算间隔多少小时，并返回          |
      | public long toMinutes()                         | 计算多少分，并返回             |
      | public long toSeconds()                         | 计算多少秒，并返回             |
      | public long toMillis()                          | 计算隔多少毫秒，并返回           |
      | public long toNanos()                           | 计算隔多少纳秒，并返回           |

#### **Arrays**类
*用来操作数组的一个工具类*
* 常见方法：

    | 方法名                                                                | 说明               |
    |--------------------------------------------------------------------|------------------|
    | public static String toString(类型[] arr)                            | 返回数组内容           |
    | public static int[] copyOfRange(类型[] arr, 起始索引, 结束索引)              | 拷贝数组(指定范围)       |
    | public static copyOf(类型[] arr, int newLength)                      | 拷贝数组             |
    | public static setAll(double[] array, IntToDoubleFunction generator | 把数组中的原数据改为新数据    |
    | public static void sort(类型[] arr)                                  | 对数组进行排序(默认是升序排序) |

* 如何让sort比较类：
  * 方式一：让该对象的类实现Comparable(比较规则)接口，然后重写compareTo方法，自己来制定比较规则
  * 方式二：使用下面这个sort方法，创建Comparator比较器接口的匿名内部类对象，然后自己制定比较规则
    >public static <T> void sort(T[] arr, Comparator<? super T>c) 对数组进行排序(支持自定义排序规则)
* 自定义排序规则时，需遵循官方约定：
  * 如果认为左边对象>右边对象，应返回正整数
  * 如果认为左边对象<右边对象，应返回负整数
  * 如果认为左边对象=右边对象，应返回0
#### **JDK8**新特性

  * **Lambda**表达式：
      *Lambda表达式是JDK8开始新增的一种语法形式*  
      *作用：用于化简匿名内部类的代码写法*
    * 格式：
      ```
      (被重写方法的形参列表)->{  
          被重写方法的方法体代码  
      }
      ```
    * 注意：
      *Lambda表达式并不是说能简化全部匿名内部类的写法，只能简化函数式接口(接口中仅有一个抽象方法)的匿名内部类*
    * 省略写法：
      * 参数类型可以省略不写
      * 如果只有一个参数，参数类型可以省略，同时()也可以省略
      * 如果Lambda表达式中的方法体代码只有一行，可以省略大括号不写，同时要省略分号！此时，如果这行代码是return语句，也必须去掉return不写

    * 方法引用：
      * 静态方法引用：  
        *如果某个Lambda表达式里只是调用一个静态方法，而且前后参数的形式一致，就可以使用静态方法引用*
        >类名::静态方法 
      * 实例方法引用：  
        *如果某个lambda表达式里只是调用一个实例方法，而且前后参数的形式一致，就可以使用实例方法引用*
        >对象名::实例方法
      * 特定类型的方法引用：  
        *如果某个lambda表达式里只是调用一个实例方法，并且前面参数列表中的第一个参数是作为方法的主调，后面的所有参数都是作为该实例方法的入参的，则此时就可以使用特定类型的方法引用* 
        >类型::方法
      * 构造器引用：  
        *如果某个lambda表达式里只是在创建对象，并且前后参数情况一致，就可以使用构造器引用*
        >类名::new

#### 正则表达式
*就是由一些特定的字符组成，代表的是一个规则*  
*用来校验数据格式是否合法*  
*在一段文本中查找满足要求的内容*  
* 使用方法
  * String提供了一个匹配正则表达式的方法：
    >public boolean matches(String regex)：  判断字符串是否匹配正则表达式，匹配返回true，不匹配返回false
* 书写规则：

    | 符号   | 含义         |
    |------|------------|
    | ?    | 一次或0次      |
    | *    | 0次或多次      |
    | +    | 一次或多次      |
    | {}   | 具体次数       |
    | (?i) | 忽略后面字符大小写  |
    | []   | 里面的内容只出现一次 |
    | ^    | 取反         |
    | &&   | 交集，不能写单个&  |
    | .    | 任意字符       |
    | \    | 转义字符       |
    | \\d  | 0-9        |
    | \\D  | 非0-9       |
    | \\s  | 空白字符       |
    | \\S  | 非空白字符      |
    | \\w  | 单词字符       |
    | \\W  | 非单词字符      |
    | ()   | 分组         |

* 举例：

    | 正则表达式(字符类：只匹配单个字符) | 含义             |
    |--------------------|----------------|
    | [abc]              | 只能是a,b或c       |
    | [^abc]             | 除了a,b,c之外的任何字符 |
    | [a-zA-Z]           | a到z,A到Z(包括首尾)  |
    | [a-d[m-p]]         | a到d,或m到p       |
    | [a-z&&[def]]       | d,e,f(交集)      |
    | [a-z&&[^bc]]       | a到z,除了b和c      |
    | [a-z&&[^m-p]]      | a到z,除了m到p      |
    | 预定义字符(只匹配单个字符)     | 含义             |
    | .                  | 任何字符           |
    | \\d                | 一个数字：[0-9]     |
    | \\D                | 非数字：[^0-9]     |
    | \\s                | 一个空白字符         |
    | \\S                | 非空白字符：[^\s]    |
    | \\w                | [a-zA-Z_0-9]   |
    | \\W                | [^\w]一个非单词字符   |
    | 数量词                | 含义             |
    | X?                 | X,一次或0次        |
    | X*                 | X,0次或多次        |
    | X+                 | X,一次或多次        |
    | X{n}               | X,正好n次         |
    | X{n,}              | X,至少n次         |
    | X{n,m}             | X,至少n次但不超过m次   |
    | a((?i)b)c          | 只忽略b的大小写       |
* 正则表达式用于搜索替换、分割内容：
    
    | 方法名                                                   | 说明                         |
    |-------------------------------------------------------|----------------------------|
    | public String replaceAll(String regex, String newStr) | 按照正则表达式匹配的内容进行替换           |
    | public String[] spilt(String regex)                   | 按照正则表达式的内容进行分割字符，返回一个字符串数组 |

#### 异常
*Exception，代表程序可能出现的问题，分为运行时异常与编译时异常*
* 异常种类
  * 运行时异常：RuntimeException及其子类，编译阶段不会出现错误提醒，运行时出现的异常(如：数组索引越界异常)
  * 编译时异常：编译阶段就会出现错误提醒(如：日期解析异常)

* 异常处理：
  * 抛出异常(throws)
    * 在方法上使用throws关键字，可以将方法内部出现的异常抛出去给调用者处理
      ```
        方法 throws 异常1,异常2,异常3……{
            ……
        }
      ```
    
    * 推荐方式：(Exception代表可以捕获的一切异常)
      ```
        方法 throws Exception{
      
        }
      ```
    * 捕获异常(try……catch)
      * 直接捕获程序出现的异常 
      ```
        try{
            //监视可能出现异常的代码
        }catch(异常类型1 变量){
            //处理异常 
        }catch(异常类型2 变量){
            //处理异常
        }……
      ```
      * 推荐方式：(Exception代表可以捕获的一切异常)
      ```
        try{
           //可能出现异常的代码
        }catch(Exception e){
           e.printStackTrace();直接打印异常对象的信息
        } 
      ```     
      
* 自定义异常
  * 自定义运行时异常：编译阶段不报错，提醒不强烈，运行时可能出现
    * 定义一个异常类继承RunTimeException
    * 重写构造器
    * 通过throw new 异常类(xxx)来创建异常对象并抛出
  * 自定义编译时异常：编译阶段就报错，提醒更加强烈
    * 定义一个异常类继承Exception
    * 重写构造器
    * 通过throw new 异常类(xxx)来创建异常对象并抛出
* 作用
  * 异常是用来查询系统Bug的关键参考信息
  * 异常可以作为方法内部的一种特殊返回值，以便通知上层调用者底层的执行情况

------
#### IO流

* File类的作用
   File类对象可以封装要操作的文件，可通过File类的对象对文件进行操作，如查看文件的大小、判断文件是否隐藏、判断文件是否可读等

   局限：File类的相关操作下，并不涉及文件相关的操作，这是单独依靠File类对象无法实现的操作，此时需要借助I/O流完成

*将I/O流理解为一根管子，I为Input,O为Output,则这根“管子”连接文件与程序的输入与输出*

* I/O流的分类
1. 按照方向划分：输入流、输出流
2. 按照处理单元划分：字节流、字符流
3. 按照功能划分：节点流、处理流

* I/O流体系结构

|分类|字节输入流|字节输出流|字符输入流|字符输出流|
|-|-|-|-|-|
|抽象基类|InputStream|OutputStream|Reader|Writer|
|访问文件|FileInputStream|FileOutoutStream|FileReader|FileWriter|
|访问数组|||||