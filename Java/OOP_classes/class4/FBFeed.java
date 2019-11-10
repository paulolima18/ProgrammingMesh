import java.util.List;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.Optional;
import java.util.Iterator;
import java.util.Comparator;
import java.util.TreeSet;

public class FBFeed {

  private List<FBPost> feed;

  public FBFeed()
  {
    this.feed = new ArrayList<FBPost>();
  }

  public FBFeed(List<FBPost> feed)
  {
    this.feed = feed.stream().collect(Collectors.toList());
  }

  public FBFeed(FBFeed feed)
  {
    this.feed = feed.getFeed();
  }

  public List<FBPost> getFeed()
  {
    return this.feed.stream().map(FBPost::clone).collect(Collectors.toList());
  }

  public void addPost(FBPost p)
  {
    if (!this.hasPost(p.getId()))
      this.feed.add(p.clone());
  }

  private boolean hasPost (int id)
  {
    return this.feed.stream().anyMatch(post -> post.getId() == id);
  }

  private boolean hasPostExt (int id)
  {
    Iterator<FBPost> it = this.feed.iterator();
    boolean encounter = false;

    while (!encounter && it.hasNext())
    {
      FBPost post = it.next();
      if (post.getId() == id)
        encounter = true;
    }
    return encounter;
  }

  public FBPost getPost(int id)
  {

    Iterator <FBPost> it = this.feed.iterator();
    boolean encounter = false;
    FBPost post = null;
    while (!encounter && it.hasNext())
    {
      post = it.next();
      if (post.getId() == id)
        encounter = true;
    }
    return encounter ? post.clone() : null;

    //return this.feed.stream().filter(post -> post.getId() == id).findFirst().get().clone();
    //Optional<FBPost> p = this.feed.stream().filter(post -> post.getId() == id).findFirst();
    //return p.isPresent
  }

  public void comment(int postId,String comentario)
  {
    //this.getPost(postId).addComment(comentario);
    this.feed.stream().filter(post -> post.getId() == postId)
                      .findFirst()
                      .get()
                      .addComment(comentario);
  }

  public int nrPosts(String user)
  {
    int count = 0;
    for(FBPost p:this.feed)
    {
      if (p.getUsername().equals(user))
        count++;
    }
    return count;
    //return this.feed.stream().filter(p -> p.getUsername().equals(user))
    //                         .map(FBPost :: clone)
    //                         .collect(Collectors.toList());
    //return this.feed.stream().filter(p -> user.equals(p.getUsername())).collect(Collectors.toList()).size();
  }

  public List<Integer> top5Comments()
  {
    Comparator<FBPost> c = (FBPost p1,FBPost p2) -> {
      if (p1.getComentarios().size() > p2.getComentarios().size())
        return 1;
      if (p1.getComentarios().size() < p2.getComentarios().size())
        return 0;
      return 0;
    };

    return this.feed.stream().sorted(c).limit(5).map(FBPost::getId).collect(Collectors.toList());
  }
}
