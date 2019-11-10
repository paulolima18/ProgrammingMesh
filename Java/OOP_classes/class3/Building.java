public class Building
{
  private String id;
  private Lamp[][] hall,class;
  
  public Building(String id,int ncorr,Lamp lc, int nsalas,
                  int nlsala,Lamp ls)
  {
    this.hall = new Lamp[ncorr][nlcorr];
    for (int i = 0; i < ncorr; i++)
      for (int j = 0; j < nlcorr; j++)
        hall[i][j] = lc.clone();

    this.class = new Lamp[nsalas][nsalas];
    for (int i=0; i<nsalas;i++ )
      for (int j=0;i<nlsala ;j++ )
        salas[i][j] = ls.clone();

  }
  public void hallON()
  {
    for (Lamp[] hall : halls)
      for (Lamp l : hall)
        l.lampOn();
  }

  public void salaON(int i)
  {
    for (Lamp l: salas[i] )
      l.lampOn();
  }
}
