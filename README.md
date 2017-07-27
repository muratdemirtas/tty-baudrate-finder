# tty-baudrate-finder
repository containing example to find tty devices baudrate. Compiled under Ubuntu 17.01 and GCC Version 6.3.0 

## Usage

    $ git clone https://github.com/muratdemirtas/tty-baudrate-finder.git
    $ sudo su
    $ cd tty-baudrate-finder
    $ gcc find_tty_baudrate.c -o finder
    
    
## if you want to know current terminal speed:
    $ ./finder 
   
## to find special device speed:
    $ ./finder < /dev/ttyS0
  
## to find USB communication device speed:
    $ ./finder < /dev/ttyACM0

## to find USB device speed:
    $ ./finder < /dev/ttyUSB0
    
## example
![alt tag](http://image-store.slidesharecdn.com/ced6a62b-3944-4418-9071-0ee33c5ccdd6-original.png)
