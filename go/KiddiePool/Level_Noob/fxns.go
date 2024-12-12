package main

// importing multiple packages
import (
    "fmt"
    "errors"
)

// NOTE: The starting curly brace has to be on the same
// line as the function name declaration.
func voidFunction() {
    fmt.Println(" - This is a basic function - ")
}

// function that require arguments
func acceptArgsFxn(name string){
    fmt.Println(" - This function accepts a name of type string:", name,"- ")
}

// function that return a value
func cubeValFxn(val int) (int){
   return val*val*val
}

// function that returns multiple values and accepts multiple arguments
func getDecimalAndPercentage(num int, den int) (float32, float32){
    a := float32(num)/float32(den)
    b := a*100
    return a,b
}

// NOTE: GoLang does not allow for default values, but one workaround 
//    is to use the ... before the type declaration. This makes the 
//    argument an optional array.

// This function requires one argument and one optional argument
// division of 0 causes an error in Go, so this form of division 
// must be checked to avoid errors. This function uses the errors
// package to return an error type
func quotient(val1 int, val2 ...int) (float32, error){
    var err error
    var v2 int
    if len(val2) > 0{
        v2 = val2[0]
    }
    if v2 == 0 {
       err = errors.New("Cannot divide by Zero!")
       return 0, err
    }
    return float32(val1)/float32(v2), err
}

// fxn using switch statement
// NOTE: break is implied in Go
func divisibleBy2or3(val int) (error) {
    var err error
    // check for valid argument
    if val < 1{
	err = errors.New("\tERROR: Poor number entry, please provide a value greater than 0")
	// Exit early
	return err
    }

    a:= val%3 == 0
    b:= val%2 == 0
    switch {
        case a && b:
	    fmt.Printf("\t%v is divisible by 3 & 2\n", val)
	case a:
            fmt.Printf("\t%v is divisible by 3\n", val)
	case b:
	    fmt.Printf("\t%v is divisible by 2\n", val)
	default:
            fmt.Printf("\t%v is neither divisible by 3 nor 2\n", val)
    }

    return err

}

func main(){
   voidFunction()
   acceptArgsFxn("testing")
   fmt.Println(" - This fxn will return the cubed result of 3:",cubeValFxn(3),"- ")
   a,b := getDecimalAndPercentage(1,3)
   // The printf function allows you to include variables in the printing string
   // NOTE: To print the % symbol, double "%%" must be used for text output
   fmt.Printf(" - This fxn returns the decimal & percentage value of a fraction 1/3: %v : %v%% - \n", a, b)
   // bad division check vs good division
   c,d := quotient(1,2)

   // because variables MUST be used, this is a common design pattern in Go, so the
   // variable is used but not printed to the screen
   if d == nil{
       fmt.Printf(" - The quotient of 1/2 = %v - \n", c)
   }
   e,f := quotient(1)
   if f != nil {
       fmt.Printf(" - The bad quotient of 1/0 returned a failing value of %v, with the error: %v - \n", e, f)
   }

   fmt.Println(" - Running fxn w/ switch statement - ")
   for i := 0; i < 7; i++ {
       err := divisibleBy2or3(i)
       if err!=nil {
           fmt.Println(err)
       }
   }
}
