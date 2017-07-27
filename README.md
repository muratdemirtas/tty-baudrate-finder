# tty-baudrate-finder
repository  containing example to find tty device baudrate.

## Usage
To insert the module into the kernel, run:

    $ git clone https://github.com/muratdemirtas/tty-baudrate-finder.git
    $ sudo su
    $ cd tty-baudrate-finder
    $ gcc find_tty_baudrate.c -o finder
    $ ./finder < /dev/ttyS0
