import java.util.List;
import java.util.ArrayList;

public class Playlist
{
  private List<Music> playlist;

  /*
  * Empty Constructor */

  public Playlist()
  {
    this.playlist = new ArrayList<>();
  }

  /*
  * Param Constructor */

  public Playlist(List<Music> playlist)
  {
    this.playlist = playlist;
  }

  /*
  * Gets */

  public List<Music> getPlaylist()
  {
    List<Music> newList = new ArrayList<Music>(this.playlist);
    return newList;
  }


  /*
  * Sets */

  public void setPlaylist(List<Music> playlist)
  {
    this.playlist = playlist;
  }

  /*
  * toString */

  public String toString()
  {
    return "Songs in playlist: " + this.playlist.toString(); 
  }
}
