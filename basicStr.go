package main
import "fmt"

func printByChar(s string) {
    for i, c := range(s) {
		fmt.Println(i ,c)
	}
	
}

func main() {
	str := "Hello, world."
	printByChar(str)
	fmt.Println(str[2:])
	fmt.Println(str[1])
}
