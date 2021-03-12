# errknow

A small utility for describing errno error codes and error names.

`usage: errknow [error code|error name]`

![Example usage](example.png)

Running `errknow` without any arguments will cause it to give information on every error.

## Building

To build `errknow`, run `make`.
To configure build flags, modify the `CFLAGS` and `LDFLAGS` environment variables.  

By default, `errknow` is installed under `/usr/local/bin`
but this can be changed by setting the `PREFIX` environment variable
to your preferred path.
