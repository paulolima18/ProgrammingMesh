import java.util.Date;
public class File1
{
  //Ex1
  public double celsiusToFarenheit(double degrees)
  {
    return degrees*9/5+32;
  }
  //Ex2
  public int max(int a,int b)
  {
    int max;
    if(a > b)
      max = a;
    else
      max = b;
    return max;
  }
  //Ex3
  public String createAccountDescription(String name,double balance)
  {
    return (name+" has "+balance+" euros");
  }
  //Ex4
  public double eurosToPounds(double value,double rate)
  {
    return value*rate;
  }
  //Ex5
  public String reOrder(int a,int b)
  {
    int max;
    double ava;
    ava = ((double)a+b)/2;
    if(a == max(a,b))
    {
      max = a;
      a = b;
    }
    else
    {
      max = b;
      a = a;
    }
    return ("First "+max+" then "+a+" Average "+ava);
  }
  //Ex6
  public long factorial(int n)
  {
    return n>0? n*factorial(n-1):1;
    //if (n==0 || n==1) return 1;
    //else return (n*factorial(n-1));
  }
  //Ex7
  public long timeSpent()
  {
    System.out.println(new Date());
    long start = System.currentTimeMillis();
    factorial(5000);
    long end = System.currentTimeMillis()-start;
    return  end;
  }
}
