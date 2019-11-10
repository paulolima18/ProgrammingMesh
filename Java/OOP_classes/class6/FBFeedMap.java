import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

public class FBFeedMap
{

  private Map<String,List<FBPost>> feed;

  public void FBFeedMap()
  {
    this.feed = new HashMap<String,List<FBPost>>();
  }

  public void FBFeedMap(String str, List<FBPost> posts)
  {
    this.feed.put(str,posts);
  }

  public void FBFeedMap(Map<String, List<FBPost>> feed)
  {
    this.feed.putAll(feed);
  }

  public void addPost (String user,FBPost post)
  {
    List<FBPost> p = new ArrayList<>();
    p = this.feed.get(user);

    if ( p != null)
    {
      for ( List<FBPost> value : this.feed.values())
        if ( value == p)
        {
          value.add(post);
          this.feed.put(user,value);
        }
    }
  }

  public List<FBPost> timelineGlobal()
  {
    return this.feed.values().stream()
                             .flatMap(l -> l.stream())
                             .map(FBPost::clone)
                             .collect(Collectors.toList())
  }

}
