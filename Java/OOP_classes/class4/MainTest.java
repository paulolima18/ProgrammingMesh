import java.time.LocalDateTime;
import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class MainTest
{
  public static void printFeed (FBFeed feed)
  {
    for (FBPost f : feed.getFeed())
    {
      System.out.println(f.toString());
    }
    //System.out.println(feed.getFeed().stream().map(p -> p.getPost()).collect(Collectors.toList()));
  }

  public static void main(String[] argvs)
  {
    /*
    MyStack s1 = new MyStack();
    MyStack s2 = s1.clone();

    System.out.println("Same? "+s1.equals(s2));

    s2.push("U.M.");
    s2.push("F.E.U.P.");

    System.out.println("Different? "+!s1.equals(s2));

    MyStack s3 = new MyStack(s2.getList());
    System.out.println("Equals? "+s3.equals(s2));

    while (!s3.empty())
    {
      s1.push(s3.pop());
    }

    System.out.println("Different? "+!s1.equals(s2));
    */
    //System.out.println("22/03/2019");
    LocalDateTime d1 = LocalDateTime.now();
    List<String> list = new ArrayList<String>();
    list.add("Hi my name is");
    list.add("Hi my name is...");

    FBPost post = new FBPost(69, "JOHN CENA", d1.now(), "WWE, agreed", 200, list);
		FBPost post2 = new FBPost(70, "OBAMA", d1.now(), "America, agreed", 10, list);

		//post.comment(69, "noob");
		//post2.comment(70, "noob");
    FBFeed feed = new FBFeed();

    feed.addPost(post);
    feed.addPost(post2);

    printFeed(feed);
    System.out.println("Top 5 MTV : " + feed.top5Comments());
  }
}
