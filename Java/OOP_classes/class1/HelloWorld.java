import java.util.Scanner;
public class HelloWorld
{
  /** One method [javadoc documentation]
      @author DarkCodex
      @version 1*/
  /* Like
     C*/
  // like C
  public static String createHello(String name)
  {
    return "Hello "+name+"!";
  }
  /** Start */
  public static void main(String[] args)
  {
    String hello = createHello("John");
    System.out.println(hello);
    Scanner is = new Scanner(System.in);
    String name;
    name = is.nextLine();
    System.out.println(name);
  }
}
