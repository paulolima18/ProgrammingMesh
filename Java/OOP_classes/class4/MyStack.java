import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class MyStack
{
  private ArrayList<String> list;
  //private List<String> list;
  public MyStack ()
  {
    this.list = new ArrayList<String>();
  }

  public MyStack (List<String> list)
  {
    this();
    for (String s: list)
      this.list.add(s);

    //this.list = list.stream().collect(Collectors.toList());
  }

  public MyStack (MyStack s)
  {
    this(s.getList());
  }

  public List<String> getList ()
  {
    return this.list.stream().collect(Collectors.toList());
  }

  public MyStack clone()
  {
    return new MyStack(this);
  }

  private int headIndex()
  {
    return this.list.size()-1;
  }
  public String top ()
  {
    return this.list.get(this.headIndex());
  }

  public void push (String s)
  {
    this.list.add(s);
  }

  public String pop ()
  {
    return this.list.remove(this.headIndex());
  }

  public boolean empty()
  {
    return this.list.isEmpty();
  }

  public String toString()
  {
    return this.list.toString();
  }

  public boolean equals(Object o)
  {
    if (o == this) return true;
    if (o == null || o.getClass() != this.getClass())
      return false;

    MyStack s = (MyStack) o;

    return this.list.equals(s.getList());
  }
  public int length()
  {
    return this.list.size();
  }

}
