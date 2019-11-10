import java.time.LocalDate;
import java.time.*;

import java.io.Serializable;

public class Aluguer implements Serializable
{
  private String codCliente;
  private String codImovel;
  private LocalDate dataInicio;
  private LocalDate dataFim;

  public Aluguer()
  {
    this.codCliente = "123";
    this.codImovel = "Bungalow";
    this.dataInicio = LocalDate.now();
    this.dataFim = LocalDate.of(2019, Month.JUNE, 10);
  }
  public String getCodImovel()
  {
    return this.codImovel;
  }
  public LocalDate getDataInicio()
  {
    return this.dataInicio;
  }
  public LocalDate getDataFim()
  {
    return this.dataFim;
  }
}
