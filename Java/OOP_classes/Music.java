public class Music
{
  private String lyrics;
  private String name;
  private double length;

  /*
  * Empty Constructor */

  public Music()
  {
    this.lyrics = "N/E";
    this.name = "N/E";
    this.length = 0.0;
  }

  /*
  * Param Constructor */

  public Music(String lyrics, String name, double length)
  {
    this.lyrics = lyrics;
    this.name = name;
    this.length = length;
  }

  /*
  * Gets */

  public String getLyrics()
  {
    return this.lyrics;
  }

  public String getName()
  {
    return this.name;
  }

  public Double getLength()
  {
    return this.length;
  }

  /*
  * Sets */

  public void setLyrics(String lyrics)
  {
    this.lyrics = lyrics;
  }

  public void setName(String name)
  {
    this.name = name;
  }

  public void setLength(double length)
  {
    this.length = length;
  }

  /*
  * toString */

  public String toString()
  {
    return "Song " + this.name + ", length: " + this.length + "minutes.\n"
            + this.lyrics;
  }
}
