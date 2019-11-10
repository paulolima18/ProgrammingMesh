import java.util.List;
import java.util.ArrayList;

import java.io.Serializable;

public class Cliente implements Serializable
{
  private String nome;
  private String codCliente;
  private List<Aluguer> meusAlugueres;

  public Cliente()
  {
    this.nome = "";
    this.codCliente = "";
    this.meusAlugueres = new ArrayList<>();
  }

  public Cliente(String cod)
  {
    this.nome = "";
    this.codCliente = cod;
    this.meusAlugueres = new ArrayList<>();
  }

  public void addAluguer(Aluguer al)
  {
    this.meusAlugueres.add(al);
  }

  public String getCodCliente()
  {
    return this.codCliente;
  }

  public List<Aluguer> getAlugueres()
  {
    return this.meusAlugueres;
  }
}
