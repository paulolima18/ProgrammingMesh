public class Moradia extends Imovel
{
  private double areaPrivativa;
  private double areaExterior;

  public Moradia()
  {
    super("Moradia","","",0,50.0);
    this.areaPrivativa = 0.0;
    this.areaExterior = 0.0;
  }

  public double precoDia()
  {
    return (this.getPrecoBase() * (0.3*areaPrivativa + 0.7*areaExterior));
  }
}
