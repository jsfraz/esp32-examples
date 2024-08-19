package main

import (
	"machine"
	"time"
)

func main() {
	machine.Serial.Configure(machine.UARTConfig{BaudRate: 9600})
	for {
		machine.Serial.Write([]byte("Hello, World!\n"))
		time.Sleep(time.Second)
	}
}
