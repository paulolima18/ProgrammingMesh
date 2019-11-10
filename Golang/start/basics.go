package main

import "fmt"

func main() {

  /* Running a go program
     $go run name_of_program.go
  */
  
  // Basic Golang Syntax
  fmt.Printf("Hello World\n")
  fmt.Println("Hello 2")

  var x_int = 2
  var y_int = x_int + 2
  // var z = 10
  var hello_str = "Hi"

  var pi_float = 3.14

  var zero int

  fmt.Println(zero) // prints 0
  fmt.Println(x_int + y_int) // prints sum of x and y
  fmt.Println(hello_str) // prints string (hello_str)
  fmt.Printf("%T\n",pi_float) // prints pi

  var test,test2 int
  test,test2 = 13,14 // value are attributed easily
  test++ // make it 14
  fmt.Println(test+test2)

  const miss = "Miss " // var set as constant (value cant be changed)
  // miss += "Mary " (string concatenation)
  fmt.Println(miss + "Catherine")

  // Golang basic syntax is very similar to python
}
