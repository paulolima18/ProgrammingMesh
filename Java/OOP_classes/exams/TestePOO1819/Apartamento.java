public class Apartamento extends Imovel
{
  private String andar;
  private double factorQualidade;

  public Apartamento()
  {
    super("Apartamento","","",0,50.0);
    this.andar = "";
    this.factorQualidade = 0.0;
  }

  public double precoDia()
  {
    return (this.getPrecoBase() * factorQualidade);
  }

}
