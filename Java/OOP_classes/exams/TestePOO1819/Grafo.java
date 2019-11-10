import java.util.Set;
import java.util.Map;
import java.util.HashMap;
import java.util.HashSet;

public class Grafo
{
  private Map<String, Set<String>> adj;

  public Grafo()
  {
    this.adj = new HashMap<>();
  }
  public void addArco(String vOrig, String vDest)
  {
    if (adj.containsKey(vOrig))
    {
      Set cena = adj.get(vOrig);
      cena.add(vDest);
      adj.replace(vOrig, cena);
    }
    else
    {
      Set cena = new HashSet();
      cena.add(vDest);
      adj.put(vOrig, cena);
    }
  }

  public int sizeGraf()
  {
    int total = 0;
    for (String key : adj.keySet())
    {
      total = total + 1 + adj.get(key).size();
    }
    return total;
  }

  public boolean haCaminho(String vOrig, String vDest)
  {
    if (adj.containsKey(vOrig))
    {
      for (String key : adj.get(vOrig))
      {
        if (key.equals(vDest)) { return true;}
        else { haCaminho(key,vDest);}
      }
    }
    return false;
  }
}
