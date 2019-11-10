import java.util.Comparator;

public class ComparadorLugarTempo implements Comparator<Lugar>
{
  public int compare (Lugar l1,Lugar l2)
  {
    int x;
    if ( l1.getMinutos() < l2.getMinutos() )
      x = -1;
    else if ( l1.getMinutos() > l2.getMinutos() )
      x = 1;
    else
      x = l1.getNome().compareTo(l2.getNome());
      
    return x;
  }
}
