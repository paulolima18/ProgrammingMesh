import java.util.ArrayList;
import java.util.List;

public class PolyAsList implements Poly
{
  private List<Double> polinomio;

  public PolyAsList()
  {
    this.polinomio = new ArrayList<>();
  }

  public void addMonomio(Double coef, int grau)
  {
    int size = this.polinomio.size();
    if (size > grau) polinomio.set(grau,polinomio.get(grau)+coef);
    else
    {
      for (int i = size;i < grau;i++)
      {
        polinomio.add(0.0);
      }
      polinomio.add(coef);
    }
  }

  public double calcula(double x)
  {
    double count = 0;
    double result = 0;
    for (double y : this.polinomio)
    {
      result = result + Math.pow(y*x,count);
      count = count + 1;
    }
    return result;
  }

  public Poly derivada()
  {
    Poly poly = new PolyAsList();
    double count = 0;
    for (double x : this.polinomio)
    {
      if ( count != 0) poly.addMonomio(x*count,(int)(count-1));
      count ++;
    }
    return poly;
  }

  public void printPoly()
  {
    System.out.println(this.polinomio.toString());
  }
}
