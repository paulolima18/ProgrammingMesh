package main

import "fmt"

func main(){

  /* Format is very important in golang */

  if(3 > 2) { // it is always true
	fmt.Println("Hello")
    if("hi" == "hi") {
        fmt.Println("String comparison true")
    }
  } else if(false) {
     // this will never run because false is always false
  } else {
    // this will also never run
  }

  for counter := 0;  counter < 3; counter++ { // it will print 3 timees
    fmt.Println("Current count",counter)
  }

  c:=3
  for c>0 { // This for behaves like a while
    fmt.Println(c)
    c--
  }

  switch {
    case (1 == 1):
      fmt.Println("True")
      fallthrough
    case (2 == 3):
      fmt.Println("Will print this either way")
    default:
      fmt.Println("Hello")
  }

}
