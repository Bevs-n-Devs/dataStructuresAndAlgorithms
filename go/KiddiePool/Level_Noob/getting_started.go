// required on the first line of every go file
// all files in the same directory MUST have the same
// package name
package main

// fmt is a built-in package within Go; it can be 
// thought of as the "standard library" similar to C++
// NOTE: Go will not compile a file, if an import is not used
import "fmt"

// the len function returns the size of a string in 
// bytes, as opposed to the number of characters. So the
// following package can be used:
import "unicode/utf8"

func variables() {
    // NOTE: GO will not compile with unused variables
    // Integer Types
    var intNum int = 65536
    var int16Num int16 = 128
    var int32Num int32 = 1000000
    var int64Num int64 = 100000000000

    // NOTE: Assigning bad values will compile, but will fail at runtime
    // e.g. Assigning a 64 bit int value to a variable declared as a 16 bit
    // int type. Be careful of this!
    // Unsigned Integer Types (don't include negative values)
    var uintNum uint = 65536
    var uint16Num uint16 = 225
    var uint32Num uint32 = 9000000
    var uint64Num uint64 = 120000000000

    var float32Num float32 = 25.45
    var float64Num float64 = 125.9634983

    var myString string = "MyStringVariable"

    fmt.Println(" - Signed Integers - ")
    fmt.Print("\tDefault int type: ")
    fmt.Println(intNum)
    fmt.Print("\tint16 type: ")
    fmt.Println(int16Num)
    fmt.Print("\tint32 type: ")
    fmt.Println(int32Num)
    fmt.Print("\tint64 type: ")
    fmt.Println(int64Num)

    fmt.Println(" - Unsigned Integers - ")
    fmt.Print("\tDefault uint type: ")
    fmt.Println(uintNum)
    fmt.Print("\tuint16t type:")
    fmt.Println(uint16Num)
    fmt.Print("\tuint32 type: ")
    fmt.Println(uint32Num)
    fmt.Print("\tuint64 type: ")
    fmt.Println(uint64Num)

    fmt.Println(" - Floating Point Values - ")
    fmt.Print("\tfloat32 type: ")
    fmt.Println(float32Num)
    fmt.Print("\tfloat64 type: ")
    fmt.Println(float64Num)

    fmt.Println(" - Casting int16 as float32 divided by 3 - ")
    fmt.Print("\t casted: ")
    fmt.Println(float32(int16Num)/3)

    fmt.Println(" - String type - ")
    fmt.Print("\tstring type: ")
    fmt.Println(myString)
    fmt.Print("\tMy string variable has ")
    // using the utf8 library
    fmt.Print(utf8.RuneCountInString(myString))
    fmt.Println(" characters")

    var myRune rune = 'a'
    fmt.Println(" - Runes - ")
    fmt.Print("\trune type: ")
    fmt.Print(myRune)
    fmt.Println(" (the ascii int value for 'a')")

    var myBool bool = true
    fmt.Println(" - Bools - ")
    fmt.Print("\tbool type: ")
    fmt.Println(myBool)


    // Default values for all variables is either 0 or '' (strings & runes)
    // The type can be inferred if a value is set when the variable is declared
    var myInferredInt = 0xFF
    myInferredFloat32 := 7.125
    varA, varB := 33, 67 
    fmt.Println(" - Inferred Types - ")
    fmt.Print("\tinferred int: ")
    fmt.Println(myInferredInt)
    fmt.Print("\tinferred float32: ")
    fmt.Println(myInferredFloat32)
    fmt.Print("\tInferred multi declaration int's: ")
    fmt.Println(varA, varB)

    const myConstString string = "192.168.1.1"
    fmt.Println(" - Const Variables - ")
    fmt.Println("\tconstant string:", myConstString)
}

// The main package is a special package in Go
// that requires a main function. If the main 
// function is not included, compilation will fail
func main(){
    fmt.Println("Hello World")
    variables()
}
