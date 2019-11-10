function pepe()
{
  if(document.getElementById("doge").getAttribute("src") == "doge.png")
  {
    document.getElementById("doge").src = "pepe.png";
  }
  else
  {
    document.getElementById("doge").src = "doge.png";
  }
}
