package main
import (
	"bufio"
	"os"
	"fmt"
)
type a struct {
	Seq int
	M map[int]int
	val interface{}
}
func Worker1(ch chan int) {
	ch <- 1
	fmt.Println("W1 Got semaphore. Entering the critical region")
	_ := <-ch
}
func Worker2(ch chan int) {
	ch <- 2
	fmt.Println("W2 Got semaphore. Entering the critical region")
	_ := <-ch
}

func main() {
	ch := make(chan int)
	go Worker1(ch)
	go Worker2(ch)
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	text, _ := reader.ReadString('\n')
	fmt.Println(text)
}