# minitalk

> **42 cursus** · C · client/server communication using UNIX signals only.

A small client–server pair that transmits a string from client to server using nothing but the two user signals `SIGUSR1` and `SIGUSR2`, bit by bit.

## Features

- Server prints its PID and waits for incoming messages
- Client encodes each character into bits sent as signals
- Bonus: acknowledgement signal and Unicode support

## Build

```bash
make        # builds server and client
```

## Usage

```bash
./server
# in another terminal, using the printed PID:
./client <SERVER_PID> "Hello world"
```

## Key concepts

UNIX signals, signal handlers and bitwise encoding.

---

*42 cursus project — [github.com/rjacquet31](https://github.com/rjacquet31)*
