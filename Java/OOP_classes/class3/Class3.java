import java.util.*;
import java.io.*;
import java.util.stream.Collectors;
public class Class3
{
  public static void main(String[] args)
  {
    Circle c1 = new Circle(1,1,1);
    Circle c2 = c1.clone();
    Lamp f = new Lamp();
    f.lampOn();
    try
    {
    Thread.sleep(200);
    }
    catch(InterruptedException ex) {
        Thread.currentThread().interrupt();
    }
    f.lampOff();
    Lamp f2 = new Lamp();
    f2.lampEco();
    try
    {
    Thread.sleep(200);
    }
    catch(InterruptedException ex) {
        Thread.currentThread().interrupt();
    }
    f2.lampOff();
    ArrayList<Lamp> array = new ArrayList<Lamp>();
    array.add(f);
    array.add(f2);
    CasaInteligente casa = new CasaInteligente(array);
    for (Lamp x : casa.collection_lamps)
    {
      System.out.println(x.getStatus());
    }
    Set<Lamp> l = casa.topConsumo(10);
    for (Lamp k : l)
    {
      System.out.println(k.getEnergyTotal());
    }
    System.out.println(casa.getCollection()
                           .stream()
                           .map(k -> (Double)k.getEnergyTotal())
                           .collect(Collectors.toList())
                      );
    //System.out.println(c2.calculateArea());
  }
}
