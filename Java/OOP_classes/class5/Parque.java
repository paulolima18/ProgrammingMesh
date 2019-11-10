import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.stream.Collectors;
import java.util.Set;
import java.util.TreeSet;

public class Parque
{
  private String nome;
  private Map <String,Lugar> lugares;

  public Parque()
  {
    this.nome = new String();
    this.lugares = new HashMap<>();
  }

  public Parque(String nome,Map <String,Lugar> lugares)
  {
    this.nome = nome;
    this.lugares = new HashMap<>();

    this.lugares = lugares.values().stream()
                          .collect(Collectors.toMap(l -> l.getMatricula()
                                                    , l -> l.clone()
                                                    ));
    /*for ( Lugar lugar : lugares.values())
      this.lugares.put(lugar.getMatricula(),lugar.clone());*/

  }

  public Parque(Parque parque)
  {
    this.nome = parque.getNome();
    this.lugares = parque.getLugares();
  }

  public String getNome()
  {
    return this.nome;
  }

  public void removeLugar(String m)
  {
    this.lugares.remove(m);
  }

  //Método que altera o temp o disp onívelde um lugar, para uma dada matricula;
  public void alteraTempo(String m,int t)
  {
    if ( this.lugares.containsKey(m) )
      this.lugares.get(m).setMinutos(t);
  }

  //Método que cria uma lista com as matriculas com tempo atribuído > x,em que o lugar seja permanente.
  public List<String> getMatriculaTempo(int m)
  {
    return this.lugares.values().stream()
                                .filter(l -> l.getMinutos() > m
                                             && l.getPermanente())
                                .map(Lugar::getMatricula)
                                .collect(Collectors.toList());
  }

  //Lista de lugares ordenados por tempo de permanencia
  public Set<Lugar> ordenarMinutos()
  {
    Set<Lugar> treeSet = new TreeSet<>(new ComparadorLugarTempo()); //Needs comparator

    for (Lugar l : this.lugares.values())
      treeSet.add(l.clone());

    return treeSet;
  }

  //Método que devolve a quantidade total de minutos atribuídos
  public int totalMinutos()
  {
    return this.lugares.values()
                       .stream()
                       .mapToInt(l -> l.getMinutos())
                       .sum();
  }

  //Método que devolve todas as matriculas dos lugares ocupados
  public void registaLugares(Lugar l)
  {
    this.lugares.put(l.getMatricula()
                    ,l.clone()
                    );
  }

  public Set <String> getMatricula()
  {
    return this.lugares.keySet();
  }

  public Map <String,Lugar> getLugares()
  {
    Map<String,Lugar> newMap = new HashMap<>();
    newMap = this.lugares.values().stream()
                                .collect(Collectors.toMap(l -> l.getMatricula()
                                                          ,l -> l.clone()
                                                          ));
    return newMap;
  }

}
