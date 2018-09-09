package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

// Complete the minimumBribes function below.
func minimumBribes(q []int32) {
    lenQ := len(q)
    var totalBribes, bribes int32
    for i := 0; i < lenQ; i++ {
        if q[i] > int32(i) {
            bribes = q[i] - int32(i + 1)
            if bribes > 2 {
                fmt.Println("Too chaotic")
                return
            }
            totalBribes += bribes
        }
    }
    fmt.Println(totalBribes)
    return
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    tTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    t := int32(tTemp)

    for tItr := 0; tItr < int(t); tItr++ {
        nTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
        checkError(err)
        n := int32(nTemp)

        qTemp := strings.Split(readLine(reader), " ")

        var q []int32

        for i := 0; i < int(n); i++ {
            qItemTemp, err := strconv.ParseInt(qTemp[i], 10, 64)
            checkError(err)
            qItem := int32(qItemTemp)
            q = append(q, qItem)
        }

        minimumBribes(q)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}
