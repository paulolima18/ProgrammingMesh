import java.util.List;
public interface Poly
{
  void addMonomio(Double coef, int grau);
  double calcula(double x);
  Poly derivada();
  void printPoly();
}
