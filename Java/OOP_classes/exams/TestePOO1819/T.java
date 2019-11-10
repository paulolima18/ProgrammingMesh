import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class T
{
  public static void main(String[] args)
  {
    Grafo graf = new Grafo();
    graf.addArco("1","2");
    graf.addArco("1","3");
    graf.addArco("1","4");

    graf.addArco("2","3");
    graf.addArco("2","4");
    graf.addArco("2","5");

    graf.addArco("3","4");
    graf.addArco("3","5");
    graf.addArco("3","6");
    System.out.println(graf.sizeGraf());
    System.out.println(graf.haCaminho("1","2"));
    // POOAirBnB air = new POOAirBnB();
    // try
    // {
    //   air = (POOAirBnB) readObject("poo.txt");
    //
    // }
    // catch (Exception e) {
    //
    // }
    //  System.out.println(air);
    //  System.out.println(air.clientesPorImovel());
    //  System.out.println(air.valorTotalAluguerCliente("1"));
    // Bungalow bung = new Bungalow();
    // Moradia mora = new Moradia();
    // Apartamento apart = new Apartamento();
    //
    // System.out.println(bung.precoDia());
    // Cliente cli1 = new Cliente("1");
    // Cliente cli2 = new Cliente("2");
    // Cliente cli3 = new Cliente("3");
    // Aluguer al = new Aluguer();
    // cli1.addAluguer(al);
    // cli2.addAluguer(al);
    // cli3.addAluguer(al);
    //
    // air.addCliente(cli1);
    // air.addCliente(cli2);
    // air.addCliente(cli3);
    //
    // air.addImovel(bung);
    // air.addImovel(mora);
    // air.addImovel(apart);
    // System.out.println(air.valorTotalAluguerCliente("1"));
    // System.out.println(air.clientesPorImovel());
    // try
    // {
    //   writeObject("poo.txt", (Object)air);
    // }catch (Exception e) {
    //
    // }

    /*Poly poly = new PolyAsList();
    poly.addMonomio(3.0,1);
    poly.addMonomio(-2.0,2);
    poly.addMonomio(1.0,0);
    poly.printPoly();
    System.out.println(poly.calcula(1.0));
    Poly newPoly = poly.derivada();
    newPoly.printPoly();*/
  }
  public static void writeObject(String filename, Object obj) throws Exception
  {
    ObjectOutputStream os = new ObjectOutputStream(new FileOutputStream(filename));
    os.writeObject(obj);
    os.close();
  }
  public static Object readObject(String filename) throws Exception
  {
    ObjectInputStream is = new ObjectInputStream(new FileInputStream(filename));
    Object mine = is.readObject();
    is.close();
    return mine;
  }
}
