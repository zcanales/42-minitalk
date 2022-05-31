# 42-minitalk 📨
* [Description](#Description)
* [Usage](#Usage)
* [Features](#Features)

# Description
The purpose of this project is to code a small data exchange program using UNIX signals.
It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

# Usage
- Mandatory
Compile:
```
make
```
Run:
```
./server
./client [server_pid] [message]
```
- Bonus:
Compile:
```
make bonus
```
Run:
```
./server
./client [server_pid] [message]
```

# Features
* Mandatory
  - The server must be launched first, and after being launched it will display its PID.
  - The client will take as parameters:
   - The server PID.
   - The string that should be sent.
  - The client sends the string passed as a parameter to the server. Once the string was received, the server will display it.
  - Communication between programs is done only using two UNIX signals: SIGUSR1 and SIGUSR2.
  - Server can receive strings from several clients in a row, without needing to be restarted.
  - The client and server support all Unicode characters.
* Bonus
  - The server confirms every signal received by sending a signal to the client.
  - Support Unicode characters!

Functions allowed
--- |
write |
ft_printf |
signal |
sigemptyset
sigaddset
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit
- Bonus
The server confirms every signal received by sending a signal to the client.
support Unicode characters!
