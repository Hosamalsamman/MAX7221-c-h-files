/*
 * segment.h
 *
 *  Created on: Dec 9, 2018
 *      Author: hosam
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <avr/io.h>

#define MOSI 5
#define SCK 7
#define SS 4
#define segments 0x02

void segment_init(void);
void segment_print(unsigned char command,unsigned char data);

#endif /* SEGMENT_H_ */
