import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

public class Lamp
{
  /*0 -> Status On
    1 -> Status Off
    2 -> Status Eco
  */
  private static final int ON = 0;
  private static final int OFF = 1;
  private static final int ECO = 2;

  private int status;
  private double energyTotal,energySinceLastReset;
  private double energyON,energyECO;
  private LocalDateTime lastReset;

  public Lamp()
  {
    this.status = 0;
    this.energyON = 10;
    this.energyECO = 5;
    this.energyTotal = 0;
    this.energySinceLastReset = 0;
    this.lastReset = LocalDateTime.now();
  }

  public Lamp(double energyON,double energyECO,double energyTotal)
  {
    this.status = OFF;
    this.energyON = energyON;
    this.energyECO = energyECO;
    this.energyTotal = 0;
    this.energySinceLastReset = 0;
    this.lastReset = LocalDateTime.now();
  }

  public Lamp(Lamp l)
  {
    this.status = l.getStatus();
    this.energyON = l.getEnergyON();
    this.energyECO = l.getEnergyECO();
    this.energyTotal = l.getEnergyTotal();
    this.lastReset = l.getLastReset();
  }

  public int getStatus()
  {
    return this.status;
  }

  public double getEnergyON()
  {
    return this.energyON;
  }

  public double getEnergyECO()
  {
    return this.energyECO;
  }

  public double getEnergyTotal()
  {
    return this.energyTotal;
  }

  public LocalDateTime getLastReset()
  {
    return this.lastReset;
  }

  public void lampOn()
  {
    this.energyTotal += this.timeSpent();
    this.status = Lamp.ON;
    this.lastReset = LocalDateTime.now();
  }

  public void lampOff()
  {
    this.energyTotal += this.timeSpent();
    this.status = Lamp.OFF;
    this.lastReset = LocalDateTime.now();
  }

  public void lampEco()
  {
    this.energyTotal += this.timeSpent();
    this.status = Lamp.ECO;
    this.lastReset = LocalDateTime.now();
  }

  public double totalEnergy()
  {
    return this.energyTotal;
  }

  public double timeSpent()
  {
    double result;
    if (this.status == OFF)
      result = 0;
    else
    {
      double spent = this.status == ON ? this.energyON : this.energyECO;
      double time = this.lastReset.until(LocalDateTime.now(),ChronoUnit.MILLIS);
      result = time * spent;
    }
    return result;
  }
}
