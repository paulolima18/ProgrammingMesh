import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class MainTest
{
  public static void main(String[] argvs)
  {
    Map<String,Lugar> map = new HashMap<String,Lugar>();
    Lugar lugar = new Lugar("11-BB-22","Pessoa1",60,true);

    Parque a = new Parque("Zé",map);
    a.registaLugares(lugar);

    //a.removeLugar("11-BB-22");

    //a.alteraTempo("11-BB-22",55);
    System.out.println("Total Minutos: "+a.totalMinutos());

    System.out.println(a.getMatricula());
  }
}
