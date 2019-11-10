import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class CasaInteligente implements Serializable{
    public ArrayList<Lamp> collection_lamps;

    public CasaInteligente() {
        this.collection_lamps = new ArrayList<Lamp>();
    }

    public CasaInteligente(Collection<Lamp> novasLamp) {
        this.collection_lamps = new ArrayList<Lamp>(novasLamp);
    }

    public Set<Lamp> topConsumo(int x)
    {
      /*
      for (Lamp lamp : this.getCollection())
      {

      }*/
      return this.getCollection()
                 .stream()
                 .limit(x)
                 .collect(Collectors.toSet());
    }


    public Collection<Lamp> getCollection()
    {
      return this.collection_lamps;
    }

}
