import java.util.List;
import java.util.ArrayList;

public class MusicPlayer
{
  public static void main(String[] args)
  {
    String alive = "Well, you can tell by the way I use my walk \nI'm a woman's man, no time to talk \nMusic loud and women warm, \nI've been kicked around since I was born\n";
    Music stayAlive = new Music(alive,"Bee Gees - Stayin' Alive",4.02);

    String dancing = "You can dance, you can jive \nHaving the time of your life \nOoh, see that girl, watch that scene \nDigging the dancing queen\n";
    Music dancingQueen = new Music(dancing,"Abba - Dancing Queen",3.51);

    String rasp = "There lived a certain man in Russia long ago \nHe was big and strong, in his eyes a flaming glow \nMost people looked at him with terror and with fear \nBut to Moscow chicks he was such a lovely dear\n";
    Music rasputin = new Music(rasp,"Boney M. - Rasputin",4.43);

    List<Music> playlist = new ArrayList<>();
    playlist.add(stayAlive);
    playlist.add(dancingQueen);
    playlist.add(rasputin);

    Playlist oldies = new Playlist(playlist);

    System.out.println(oldies.toString());

  }
}
