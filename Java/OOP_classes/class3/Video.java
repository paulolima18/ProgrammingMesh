import java.time.LocalDateTime;
import java.time.LocalTime;

public class Video
{
  private String name;
  private byte[] content;
  private LocalDateTime loadDate;
  private int resolution;
  private LocalTime duration;
  private String[] comments;
  private int numCom;//number of comments
  private int likes,dislikes;

  public Video()
  {
    this.name = "";
    this.content = new byte[0];
    this.loadDate = LocalDateTime.now();
    this.resolution = 0;
    this.duration = LocalTime.of(0,0);
    this.comments = new String[10];
    this.numCom = 0;
    this.likes = 0;
    this.dislikes = 0;
  }

  public Video(String name,byte[] content,LocalDateTime loadDate,
                int resolution,LocalTime duration,String[] comments,
                int numCom,int likes,int dislikes)
  {
    this.name = name;
    this.content = Arrays.copyOf(content,content.length);;
    this.loadDate = loadDate;
    this.resolution = resolution;
    this.duration = duration;
    this.comments = Arrays.copyOf(comments,comments.length);;
    this.numCom = numCom;
    this.likes = likes;
    this.dislikes = dislikes;
  }

  public Video (Video v)
  {
    this.name = v.getName();
    this.content = v.getContent();
    this.loadDate = v.getLoadDate();

    this.resolution = v.getResolution();
    this.duration = v.getDuration();
    this.comments = v.getComments();

    this.numCom = v.getNumCom();
    this.likes = v.getLikes();
    this.dislikes = v.getDislikes();
  }

  public String[] getComments()
  {
    return Arrays.copyOf(this.comments,this.numCom);
  }

  public Byte[] getContent()
  {
    return Arrays.copyOf(this.content,content.length);
  }

  public String getName()
  {
    return this.name;
  }

  public LocalTime getDuration()
  {
    return this.duration;
  }

  public LocalDateTime getLoadDate()
  {
    return this.loadDate;
  }

  public int getResolution()
  {
    return this.resolution;
  }

  public int getLikes()
  {
    return this.likes;
  }

  public int getNumCom()
  {
    return this.numCom;
  }

  public int getDislikes()
  {
    return this.dislikes;
  }

  public boolean equals (Object o)
  {
    boolean bool;
    boolean same = this.numCom == v.getNumCom();
    if (this == o)
      bool = true;
    if ( o == null || this.getClass() != o.getClass())
      bool = false;

    for (int i=0;same && i < this.numCom;i++)
      same = this.comments[i].equals(v.getComments()[i]);

    bool =  this.name.equals(v.getName()) &&
            Arrays.equals(this.content,v.getContent()) &&
            this.loadDate.equals(v.getLoadDate()) &&
            this.resolution == v.getResolution() &&
            this.duration.equals(v.getDuration() &&

            Arrays.equals(this.comments,v.getComments()) &&
            this.numCom == v.getNumCom() &&
            this.likes == v.getLikes() &&
            this.dislikes == v.getDislikes();
    return bool;
  }

}
