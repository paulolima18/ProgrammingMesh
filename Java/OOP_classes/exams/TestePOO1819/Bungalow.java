public class Bungalow extends Imovel
{
  private double factorQualidade;
  private double espessuraParedes;

  public Bungalow()
  {
    super("Bungalow","","",0,50.0);
    this.factorQualidade = 1.0;
    this.espessuraParedes = 1.0;
  }

  public double precoDia()
  {
    return (this.getPrecoBase() * (0.5*factorQualidade + 0.5*espessuraParedes));
  }
}
