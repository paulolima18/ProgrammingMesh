import java.time.LocalDateTime;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.stream.Collectors;

public class MainTest
{
/*
  public static void printFeed (FBFeedMap feed)
  {
    for (FBPost f : feed.getFeed())
    {
      System.out.println(f.toString());
    }
    //System.out.println(feed.getFeed().stream().map(p -> p.getPost()).collect(Collectors.toList()));
  }*/

  public static void main(String[] argvs)
  {
    LocalDateTime d1 = LocalDateTime.now();
    List<String> list = new ArrayList<String>();
    list.add("Hi my name is");
    list.add("Hi my name is...");

    FBPost post = new FBPost(69, "JOHN CENA", d1.now(), "WWE, agreed", 200, list);
		FBPost post2 = new FBPost(70, "OBAMA", d1.now(), "America, agreed", 10, list);

    FBFeedMap feed = new FBFeedMap();

    feed.addPost("OBAMA",post);
    System.out.println("hi");

    //printFeed(feed);
    //System.out.println("Top 5 MTV : " + feed.top5Comments());
  }
}
