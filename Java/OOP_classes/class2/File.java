import java.util.Scanner;
import java.util.Arrays;

public class File
{
  public static int[] readArray()
  {
    int[] array;
    int size,i;
    Scanner is = new Scanner(System.in);
    do {
      System.out.print("Array Size: ");
      size = is.nextInt();
    } while (size < 0 );

    array = new int[size];
    System.out.println("Insert "+size+" integers: ");

    for (i = 0; i < array.length ; i++)
    {
      array[i] = is.nextInt();
    }

    //is.close();
    return array;
  }

  public static String[] readString()
  {
    String[] array;
    int size,i;
    Scanner is = new Scanner(System.in);
    do {
      System.out.print("Array Size: ");
      size = is.nextInt();
    } while (size < 0 );

    array = new String[size+1];
    System.out.println("Insert "+size+" strings: ");

    for (i = 0; i < size+1; i++)
    {
      array[i] = is.nextLine();
    }

    //is.close();
    return array;
  }

  public static void main(String [] args)
  {
    TestF f = new TestF();
    //int[] array,array2;
    int min,max;
    int[][] grades = {{1,1,1,1,2},
                      {3,4,5,4,4},
                      {3,2,2,1,2},
                      {5,3,2,1,2},
                      {1,2,3,4,1}};

    //array = readArray(); // read an array

    Scanner is = new Scanner(System.in);
    /*Ex1
    /*a-prints the minimum of an array
    min = f.min(array);
    System.out.println("The minimum is: "+min);*/
    /*b
    System.out.println("Choose the range of index: ");
    min = is.nextInt();
    max = is.nextInt();
    is.close();
    System.out.println("The new array is: "+f.range(array,min,max));*/
    /*c
    array2 = readArray();
    System.out.println("Common elements are: "+f.common(array,array2));*/
    /*Ex2*/
    /*b
    int course = is.nextInt();
    System.out.println("Sum of ["+course+"] grades is "+f.sumGrades(grades,course));*/
    /*c
    int student = is.nextInt();
    System.out.println("Students average is: "+f.average(grades,student));*/
    /*d
    int course = is.nextInt();
    System.out.println("Course average is: "+f.averageCourse(grades,course));*/
    /*e
    System.out.println("School max grade is: "+f.maxGrade(grades));*/
    /*4*/
    /*a
    System.out.println("Normal array: "+Arrays.toString(array));
    Arrays.sort(array);
    System.out.println("Ordered array: "+Arrays.toString(array));*/
    /*b
    System.out.println(Arrays.binarySearch(array,2));*/
    /*5*/
    String[] array;
    array = readString();
    //for(String str:f.stringNoRepeat(array))
    //  System.out.println(str);
    System.out.println(f.bigString(array));
  }

}

/*

-
-
-
-
-
-
-
-
--
-



















*/
