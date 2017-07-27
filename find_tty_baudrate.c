/****************************************************************************
 * Copyright (C) 2017 by Murat DEMIRTAS                                     *
 *                                                                          *
 * This file is part of Box.                                                *
 *                                                                          *
 *   Box is free software: you can redistribute it and/or modify it         *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   Box is distributed in the hope that it will be useful,                 *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Box.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

/**
 * @file find_tty_baudrate.c
 * @author Murat Demirtas <muratdemirtastr@gmail.com>
 * @date 27 June 2017
 * @brief File containing example to find tty device baudrate.
 * @see http://man7.org/linux/man-pages/man4/tty.4.html
 */


#define _POSIX_SOURCE

#include <termios.h>    //for terminal I/O interfaces
#include <stdio.h>      //for printf function.
#include <string.h>     //for strcpy function

/**
 * @brief to determine baudrate speed, speed_t is octal based variable
 * @param speed_t of tty device
 * @return speed value as char pointer
 * @see http://pubs.opengroup.org/onlinepubs/009695399/basedefs/termios.h.html
 *
 */
char *see_speed(speed_t speed) {
  static char   SPEED[20];
  switch (speed) {
    case B0:       strcpy(SPEED, "0");
                   break;
    case B50:      strcpy(SPEED, "50");
                   break;
    case B75:      strcpy(SPEED, "75");
                   break;
    case B110:     strcpy(SPEED, "110");
                   break;
    case B134:     strcpy(SPEED, "134");
                   break;
    case B150:     strcpy(SPEED, "150");
                   break;
    case B200:     strcpy(SPEED, "200");
                   break;
    case B300:     strcpy(SPEED, "300");
                   break;
    case B600:     strcpy(SPEED, "600");
                   break;
    case B1200:    strcpy(SPEED, "1200");
                   break;
    case B1800:    strcpy(SPEED, "1800");
                   break;
    case B2400:    strcpy(SPEED, "2400");
                   break;
    case B4800:    strcpy(SPEED, "4800");
                   break;
    case B9600:    strcpy(SPEED, "9600");
                   break;
    case B19200:   strcpy(SPEED, "19200");
                   break;
    case B38400:   strcpy(SPEED, "38400");
                   break;
    default:       sprintf(SPEED, "unknown baudrate detected: (%d)", (int) speed);
  }
  return SPEED;
}

/**
 * @brief main function of application
 * @return none
 * @params none
 */
int main(void) {

  printf("TTY Baudrate Finder Application forked from IBM\r\n");

  struct termios term;
  speed_t in_speed,out_speed;

  if (tcgetattr(0, &term) != 0)
    perror("tcgetattr() error");
  else {
    in_speed = cfgetispeed(&term);
    out_speed = cfgetospeed(&term);
    printf("cfgetispeed() says the speed of standart input is %s\n",
           see_speed(in_speed));
    printf("cfgetospeed() says the speed of standart output is %s\n",
           see_speed(out_speed));
  }
}
