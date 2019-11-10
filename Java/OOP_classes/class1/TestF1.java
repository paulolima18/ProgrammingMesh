import java.util.Scanner;
import java.util.Date;
public class TestF1
{
  public static void main (String[]args)
  {
    File1 f = new File1();
    Scanner is = new Scanner(System.in);
    /*Test 1
    double d;
    do
    {
      d = is.nextDouble();
      System.out.println(f.celsiusToFarenheit(d));
    } while (d != (-1));
    */
    /*Test 2
    int i,j;
    Scanner is2 = new Scanner(System.in);
    do
    {
      i = is.nextInt();
      j = is2.nextInt();
      System.out.println("The bigger number is :" + f.max(i,j));
    } while (i != -1);
    */
    /*Test 3
    double d;
    d = is.nextDouble();
    String sentence = f.createAccountDescription("John",d);
    System.out.println(sentence);
    */
    /*Test 4*/
    /*Test 5
    Scanner is2 = new Scanner(System.in);
    int i,j;
    i = is.nextInt();
    j = is2.nextInt();
    System.out.println(f.reorder(i,j));
    is.close();
    is2.close();*/
    /*Test6*/
    if(args.length > 0)
    {
      int num = Integer.parseInt(args[0]);
      System.out.println(f.factorial(num));
    }
    /*Test7*/
    System.out.println(f.timeSpent());
  }
}
