## Exam03

# [ft_printf](./ft_printf)
This mini ft_printf version has been done for learn purpposes only, not copy-pasting!
It shows how to do it in an easy and logical way.
\
This version only supports '%s' '%d' and '%x'.
- `%s` is for strings.
- `%d` is for decimal numbers.
- `%x` is for hexadecimal numbers.

- The function must be declared as:

    ```c
    int printf(const char *str, ... );
    ```

- ft_printf must return the bytes count from the message shown.

And you will have to be aware of *va_list, va_start, va_arg and va_end,* and the data types passed to functions.
\
Just like in the original ft_printf.


### 🎯 **Fun Tips & Tricks** 💡

	int main(void)
	{
	// 0 can be used as NULL
	char *ptr = 0;         // Valid
	char *ptr2 = NULL;     // Valid

	// But they're different in other contexts
	int num = 0;          // Valid
	int num2 = NULL;      // Warning: makes no sense

	// In conditions
	if (!ptr)      // Valid: checks for NULL
	if (ptr == 0)  // Valid: 0 represents NULL
	if (!num)      // Valid: checks for 0

	return (0);
	}

# [get_next_line](./get_next_line)
This function reads a line from a file descriptor until a newline character is found.

To open and close a file descriptor, you can use the `open` and `close` functions in your main program.
The `read` function is used to read data from the file descriptor into a buffer.
- The function must be declared as:

    ```c
    char *get_next_line(int fd);
    ```

- It uses a static variable to store the buffer between function calls.
- It handles memory allocation and deallocation carefully to avoid leaks.
- It uses helper functions like `ft_strdup`, `ft_substr`, `gnl_strjoin`, and `gnl_strchr` to manage strings.
- It reads from the file descriptor in chunks defined by `BUFFER_SIZE`.

The function must return the next line read from the file descriptor, or `NULL` if there is nothing more to read or an error occurs.

**Remember!**
The last line doesn't need to be freed because get_next_line returns this line to the main function, and the caller  is responsible for managing this.

---
*Proyecto desarrollado como parte del curriculum de 42.*