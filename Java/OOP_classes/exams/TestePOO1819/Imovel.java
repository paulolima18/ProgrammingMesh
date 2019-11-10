import java.io.Serializable;

public abstract class Imovel implements Serializable, Comparable<Imovel>
{
  //,Comparable<Imovel>
  private String codImovel;
  private String morada;
  private String nifProprietario;
  private double area;
  private double precoBase;
  public abstract double precoDia();

  public Imovel(String codImovel, String morada,
                String nifProprietario, double area, double precoBase )
  {
    this.codImovel = codImovel;
    this.morada = morada;
    this.nifProprietario = nifProprietario;
    this.area = area;
    this.precoBase = precoBase;
  }

  public Imovel()
  {
    this.codImovel = "";
    this.morada = "";
    this.nifProprietario = "";
    this.area = 0.0;
    this.precoBase = 50.0;
  }

  public int compareTo(Imovel i)
  {
    return  (int)(this.precoBase - i.getPrecoBase());
  }

  public double getPrecoBase()
  {
    return this.precoBase;
  }
  public String getCodImovel()
  {
    return this.codImovel;
  }
}
