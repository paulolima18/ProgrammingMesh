import java.lang.Math;

public class Circle
{
  private double x,y,radius;

  public Circle ()
  {
    this.x = this.y = 0;
    this.radius = 1;
  }

  public Circle (double x,double y,double radius)
  {
    this.x = x;
    this.y = y;
    this.radius = radius;
  }

  public Circle(Circle c)
  {
    this.x = c.getX();
    this.y = c.getY();
    this.radius = c.getRadius();
  }

  //Instance methods
  public double getX ()
  {
    return this.x;
  }

  public double getY ()
  {
    return this.y;
  }

  public double getRadius ()
  {
    return this.radius;
  }

  public void setX (double cx)
  {
    this.x = cx;
  }

  public void setY (double cy)
  {
    this.y = cy;
  }

  public void setRadius (double cradius)
  {
    this.radius = cradius;
  }

  public String toString()
  {
    return "Circle("+this.x+","+this.y+","+this.radius+")";
  }

  public boolean equals (Object o)
  {
    boolean bool;
    if (this == o)
      bool = true;
    if ( o == null || this.getClass() != o.getClass())
      bool = false;
    //possible error (work's because of getClass)
    Circle c = (Circle)o;
    bool = this.x == c.getX() && this.y == c.getY() && this.radius == c.getRadius();
    return bool;
  }

  public void changeCenter (double cx,double cy)
  {
    this.x = cx;
    this.y = cy;
  }

  public double calculateArea ()
  {
    return Math.PI*Math.pow(this.radius,2);
  }

  public double calculatePerimeter ()
  {
    return Math.PI*2*this.radius;
  }

  public Circle clone ()
  {
    return new Circle(this);
  }
}
