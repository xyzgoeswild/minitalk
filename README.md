# Minitalk

Project implementing inter-process communication in C using UNIX signals.

Minitalk allows a client process to send messages to a server process. Each character is transmitted bit by bit using `SIGUSR1` and `SIGUSR2`.

## How It Works

* The **server** starts and displays its Process ID (PID).

* The **client** takes the server's PID and a message as arguments.

* The client sends each character as a sequence of signals:

  * `SIGUSR1` represents a `1` bit.

  * `SIGUSR2` represents a `0` bit.

* The server receives the signals, reconstructs each character, and prints the message.

* A null character (`\0`) indicates the end of the message.

## Requirements

* A UNIX-like operating system

* A C compiler (`cc` or `gcc`)

* `make`

## Installation

Clone the repository and navigate to the project directory:

```
git clone https://github.com/xyzgoeswild/minitalk.git
cd minitalk
```

Compile the project:

```
make
```

This generates two executables: `server` and `client`.

## Usage

### 1. Start the Server

In your first terminal, run:

```
./server
```

The server displays its PID. Keep it running.

### 2. Send a Message

Open a second terminal and run:

```
./client <SERVER_PID> "Hello, world!"
```

Replace `<SERVER_PID>` with the PID displayed by the server.

The message will be printed in the server's terminal.

## Makefile Commands

| Command       | Description                         |
| ------------- | ----------------------------------- |
| `make`        | Compile the client and server       |
| `make clean`  | Remove object files                 |
| `make fclean` | Remove object files and executables |
| `make re`     | Clean and rebuild the project       |

## Project Structure

| File            | Description                                         |
| --------------- | --------------------------------------------------- |
| `client.c`      | Sends messages to the server using UNIX signals     |
| `server.c`      | Receives signals and reconstructs messages          |
| `mini_assist.c` | Contains helper functions                           |
| `minitalk.h`    | Shared declarations, headers, and color definitions |
| `Makefile`      | Build rules for the project                         |

## Concepts Learned

* Inter-process communication (IPC)

* UNIX signals and signal handling

* Bitwise operations

* Binary data representation

* C programming and Makefiles

---
