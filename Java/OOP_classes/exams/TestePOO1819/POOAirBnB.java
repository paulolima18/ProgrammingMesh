import java.io.Serializable;

import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Map;

import java.time.temporal.ChronoUnit;

public class POOAirBnB implements Serializable,OrdenaImoveis
{
  private Map<String, Imovel> imoveis;
  private Map<String, Cliente> clientes;

  public POOAirBnB()
  {
    this.imoveis  = new HashMap<>();
    this.clientes = new HashMap<>();
  }

  public void addCliente(Cliente cli)
  {
    this.clientes.put(cli.getCodCliente(),cli);
  }

  public void addImovel(Imovel imo)
  {
    this.imoveis.put(imo.getCodImovel(),imo);
  }

  public double valorTotalAluguerCliente(String codCliente)
  {
    Cliente cliente = clientes.get(codCliente);
    Imovel m;
    double total = 0.0, tempo_aluguer;
    for (Aluguer al : cliente.getAlugueres())
    {
      m = imoveis.get(al.getCodImovel());
      tempo_aluguer = ChronoUnit.DAYS.between(al.getDataFim(),al.getDataInicio());
      total = total + (tempo_aluguer * m.precoDia());
    }
    return total;
  }

  public Map<String, Set<String>> clientesPorImovel()
  {
    Map stuff = new HashMap<>();
    for (Cliente cli : this.clientes.values())
    {
      for (Aluguer al : cli.getAlugueres())
      {
        if (stuff.get(al.getCodImovel()) == null)
        {
          Set movel = new HashSet();
          movel.add(cli.getCodCliente());
          stuff.put(al.getCodImovel(),movel);
        }
        else
        {
          Set movel = new HashSet();
          movel = (Set) stuff.get(al.getCodImovel());
          movel.add(cli.getCodCliente());
          stuff.replace(al.getCodImovel(), movel);
        }
      }
    }
    return stuff;
  }

  public List<Imovel> imoveisPorTipoArea()
  {
    return new ArrayList<Imovel>();
  }
}
