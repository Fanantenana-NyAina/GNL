*This project has been created as part of the 42 curriculum by fananrak.*

---

# Get Next Line

## Description

**Get Next Line** is a C project from the 42 curriculum. The goal is to implement a function `get_next_line()` that reads and returns one line at a time from a file descriptor, no matter how many times it is called in a row.

```c
char    *get_next_line(int fd);
```

- Returns the line that was read, including the terminating `\n` character
- Returns `NULL` when there is nothing left to read or when an error occurs
- Works both with regular files and standard input (`stdin`)

This project introduces a key concept in C programming: **static variables** — variables that retain their value between function calls.

---

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can use any value for `BUFFER_SIZE`:

```bash
# Small buffer
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c

# Large buffer
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c

# Without flag (uses default value defined in header)
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

### Files

| File | Role |
|------|------|
| `get_next_line.h` | Header — prototypes + `BUFFER_SIZE` definition |
| `get_next_line.c` | Main function |
| `get_next_line_utils.c` | Helper functions |

### Usage example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## Algorithm

The core challenge of GNL is that `read()` does not know where lines end — it just reads chunks of `BUFFER_SIZE` bytes. A `\n` can appear anywhere inside a chunk, or span across multiple reads.

The solution relies on a **static variable** `leftover` that persists between calls and stores whatever was read beyond the last `\n`.

### Step by step

**Step 1 — Validate inputs**
```
if fd < 0 or BUFFER_SIZE <= 0 → return NULL
```

**Step 2 — `read_and_stash(fd, leftover)`**
- Allocate a buffer of `BUFFER_SIZE + 1` bytes
- Loop: read `BUFFER_SIZE` bytes from `fd` into buffer
- Concatenate buffer into `leftover` after each read
- Stop as soon as `\n` is found in `leftover` OR `read()` returns 0 (EOF)
- Return updated `leftover`

**Step 3 — `extract_line(leftover)`**
- Find the position of `\n` in `leftover`
- Return a new string from index 0 up to and including `\n`
- If no `\n` (EOF case) → return the entire remaining `leftover`
- If `leftover` is NULL or empty → return NULL

**Step 4 — `update_leftover(leftover)`**
- Keep everything after the `\n` for the next call
- Free the old `leftover`
- Return the new `leftover`

**Step 5 — Return the line**

### Concrete example

```
File       : "Hello\nWorld\n"
BUFFER_SIZE: 4

Call 1 to get_next_line():
  leftover = NULL
  read()   → "Hell"   no \n → continue
  read()   → "o\nWo"  \n found → stop
  leftover = "Hello\nWo"
  line     = "Hello\n"   ← returned
  leftover = "Wo"        ← saved for next call

Call 2 to get_next_line():
  leftover = "Wo"
  read()   → "rld\n"  \n found → stop
  leftover = "World\n"
  line     = "World\n"  ← returned
  leftover = ""

Call 3 to get_next_line():
  leftover = ""
  read()   → ""  bytes_read = 0 → EOF
  return NULL
```

### Why BUFFER_SIZE does not affect correctness

`BUFFER_SIZE` only controls how many bytes are read at a time — not the size of the returned line. The `leftover` string grows dynamically via `ft_strjoin` with each read call, so lines of any length are handled correctly regardless of `BUFFER_SIZE`.

### Helper functions used

| Function | Role |
|----------|------|
| `ft_strlen` | Get the length of a string |
| `ft_strchr` | Find `\n` in `leftover` |
| `ft_strjoin` | Concatenate `leftover` + `buffer` |
| `ft_substr` | Extract a substring from `leftover` |

---

## Resources

### Documentation
- [`read()` man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [`malloc()` / `free()` man page](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [Static variables in C — GeeksForGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
- [File descriptors in Unix](https://www.computerhope.com/jargon/f/file-descriptor.htm)
- [Understanding get_next_line — Medium](https://medium.com/@omimouni8/understanding-get-next-line-gnl-in-c-a-step-by-step-guide-9e573bb7f7c6)

### AI usage

AI (Claude — claude.ai & notebooklm — notebooklm.google) was used during this project strictly as a **learning assistant**, not to generate code. 
Specifically it was used for:

- Understanding the concept of static variables and why they persist between calls
- Visualizing how `leftover` evolves across multiple calls with concrete examples
- Understanding the role of `BUFFER_SIZE` and why it does not affect correctness
- Identifying logical errors in the read loop (missing EOF condition, missing `\n` check)
- Understanding why a linked list approach is not suited for this project

All code was written and understood.