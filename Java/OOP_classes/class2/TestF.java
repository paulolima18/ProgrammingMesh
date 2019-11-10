import java.util.Arrays;

public class TestF
{
  public int min (int[] array)
  {
    int min=0,i=0;
    while(i < array.length)
    {
      if (i > 0 && array[i]<min)
        min = array[i];
      else if (i == 0)
        min = array[i];
      i++;
    }
    return min;
  }

  public String range(int[] array,int mini,int maxi)
  {
    int[] a;
    a = new int[maxi-mini+1];
    int i=0;
    for (i=0;i <= maxi-mini;i++)
    {
      a[i] = array[mini+i];
    }
    return Arrays.toString(a);
    //int[] range()
    //return Arrays.copyOfRange(array,mini,maxi+1);
  }

  public String common(int[] array,int[] array2)
  {
    int[] a,b;
    int k=0;
    a = new int[array.length];

    for(int i =0;i<array.length;i++)
    {
      for(int j=0;j<array2.length;j++)
      {
        if(array[i] == array[j])
        {
          a[i] = array[i];
          k++;
          break;
        }
      }
    }
    b = new int[k];
    for(int i =0 ;i<k;i++)
    {
      b[i]= a[i];
    }
    return Arrays.toString(b);
  }

  public int sumGrades(int[][] matrix,int course)
  {
    int grade = 0,i=4;
    while(i>=0)
      grade = grade + matrix[i--][course];
    return grade;
  }

  public double average(int[][] matrix,int student)
  {
    double average=0;
    int i=4;
    while(i>=0)
      average = average + matrix[student][i--];
    return (average/5);
  }

  public double averageCourse(int[][] matrix,int course)
  {
    double average=0;
    int i=4;
    while(i>=0)
      average = average + matrix[i--][course];
    return (average/5);
  }

  public int maxGrade(int[][] matrix)
  {
    int max = matrix[0][0];

    for (int i =0;i<5;i++)
      for (int j = 0;j<5;j++)
        if (matrix[i][j] > max)
          max = matrix[i][j];

    return max;
  }

  public String[] stringNoRepeat(String[] array)
  {
    int i,j,k=1,size=0;
    String[] a;
    a = new String[array.length];
    for (i= 0;i<array.length;i++)
    {
      for (j= i+1;j<array.length;j++)
      {
        if (array[i].compareTo(array[j]) == 0)
        {
          k = 0;
          break;
        }
      }
      if (k != 0)
        a[size++] = array[i];

      k=1;
    }
    return a;
  }

  public String bigString(String[] array)
  {
    int k=0,size;
    for(int i=0;i < array.length;i++)
    {
      if(array[i].length() > k)
        k = i;
    }
    return array[k];
  }
}
