import java.util.Comparator;

public class CompNumQuartos implements Comparator<Hotel> {

  public int compare(Hotel h1,Hotel h2) {
    return h1.getNumQuartos()-h2.getNumQuartos();
  }

}
