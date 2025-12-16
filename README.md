_This project has been created as part of the 42 curriculum by dnovikov._

# Description

This project implements the `get_next_line` function, which reads a line from a file descriptor, handling multiple file descriptors and buffering efficiently. The goal is to provide a robust and memory-safe way to read lines of arbitrary length from files or input streams.

# Instructions

## Compilation

### To compile the project, use the following command:

Mandatory version:

```
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line
```

Bonus version:

```
gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

---

### To compile with a custom buffer size, use the `-D` flag and define `BUFFER_SIZE`:

Example for the mandatory version:

```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c -o get_next_line
```

## Usage

Include the `get_next_line.h` header in your project and call `get_next_line(fd)` to read lines from a file descriptor.

# Resources

-   [42 Subject PDF](https://cdn.intra.42.fr/pdf/pdf/675/en.subject.pdf)

# Algorithm Explanation and Justification

The algorithm reads from the file descriptor into a buffer of size `BUFFER_SIZE`, appending to a static storage for each file descriptor. It searches for newline characters to determine line boundaries, ensuring efficient memory usage and correct handling of partial reads. This approach is justified as it balances performance, memory safety, and compliance with the 42 subject requirements.
