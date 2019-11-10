import java.util.ArrayList;
import java.util.List;
import java.time.LocalDateTime;
import java.util.stream.Collectors;
public class Encomenda
{
  private List<LinhaEncomenda> list;
  private String name;
  private String adress;
  private String nFiscal;
  private int nEncomenda;
  private LocalDateTime date;

  public Encomenda()
  {
    this.list = new ArrayList<LinhaEncomenda>();
    this.name = "n/a";
    this.nFiscal = "n/a";
    this.adress = "n/a";
    this.nEncomenda = 0;
    this.date = LocalDateTime.now();
  }

  public int numeroTotalProdutos ()
  {
    return this.list.stream().mapToInt(LinhaEncomenda::getQuantidade).sum();
  }

  public void removeProduto (String codProd)
  {
    /*Iterator<LinhaEncomenda> it = this.list.iterator();
    while(it.hasNext())
    {
      LinhaEncomenda l = it.next();
      if (l.getReferencia().equal(codProd))
        it.remove();
    }*/

    this.list = this.list.stream().filter(l -> !l.getReferencia().equals(codProd)).collect(Collectors.toList());

    //this.list.removeIf(l -> l.getReferencia().equals(codProd))
  }

  public void adicionaLinha (LinhaEncomenda line)
  {
    this.line.add(line.clone());
  }

  public Encomenda(List<LinhaEncomenda> list,String name,String adress,String nFiscal,
                  int nEncomenda,LocalDateTime date)
  {
    this.name = name;
    this.nFiscal = nFiscal;
    this.adress = adress;
    this.nEncomenda = nEncomenda;
    this.date = date;

    this.list = new ArrayList<LinhaEncomenda>();
    for (LinhaEncomenda l: line)
      this.lines.add(l.clone());

    this.list = this.stream().map(l -> l.clone()).collect(Collectors.toList());
    //this.list = list.stream().map(LinhaEncomenda::clone).collect(Collectors.toList());
  }

  public Encomenda(Encomenda encomenda)
  {
    this.name = "n/a";
    this.nFiscal = "n/a";
    this.adress = "n/a";
    this.nEncomenda = encomenda.getNEncomenda();
    this.date = encomenda.getDate();

    this.list = new ArrayList<String>();
  }
  //private List<LinhaEncomenda> list;

  public LocalDateTime getDate()
  {
    return this.date;
  }

  public String getNFiscal ()
  {
    return this.nFiscal;
  }

  public String getAdress ()
  {
    return this.adress;
  }

  public String getName ()
  {
    return this.name;
  }

  public int getNEncomenda ()
  {
    return this.nEncomenda;
  }

  public void setNEncomenda(int value)
  {
    this.nEncomenda = value;
  }

  public void setNFiscal(String nFiscal)
  {
    this.nFiscal = nFiscal;
  }

  public void setName(String value)
  {
    this.name = value;
  }

  public void setAdress(String value)
  {
    this.adress = value;
  }

  public void setDate(LocalDateTime value)
  {
    this.date =
  }

  public Encomenda clone ()
  {
    return new Encomenda(this);
  }
}
