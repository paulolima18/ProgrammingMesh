package main

import (
  "fmt"
  // "strconv"
)

type Person struct{
    name string
    gender string
    age int
    height float64
}

func main(){
  arrays() // Two/Multi dimensional arrays
  pointers() // Pointers
  var john_fact = print("Madrid", "John", 20) // return of value
  var mary_fact = print("New York", "Mary", 19)

  var jack = person("Jack", "Male", 25, 1.76)

  fmt.Println(jack) // printing jack (Person) struct
  fmt.Println("---Facts---")
  fmt.Println("John worked in", john_fact)
  fmt.Println("Mary works in", mary_fact)

  var map1 = make(map[string]string)
  map1["tokyo"]="japan"
  map1["hong kong"]="china"
  // map1 := map[string]interface{}{"tokyo": "japan"}
  fmt.Println(map1)
}

func print(random,text string, age int)(string){
  fmt.Println(text + " is",age)
  return random
}

func arrays(){ // Arrays can be compared
  var int_Array = [...] int{1,2,3,4,5}
  var mult_Array = [...][3] int{{1,2}, {3,4}, {5,6}}

  fmt.Println(int_Array)
  fmt.Println(mult_Array)

  for count:= range int_Array{
    fmt.Println(count)
  }
}

func pointers(){
  var value = 12
  fmt.Println("Pointer adress:",&value)
  fmt.Println("Pointer value:",value)
}

func person(name string, gender string, age int, height float64)(Person){
  var new Person

  new.name = name
  new.gender = gender
  new.age = age
  new.height = height

  return new
}

func slices(){
  var slice []int

  slice = append(slice, 1, 2, 3, 4)
  slice = append(slice[:2], slice[3:]...)
  fmt.Println("Slice", slice)
}
