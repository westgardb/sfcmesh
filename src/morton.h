/*
 * Morton Order Encoding implementation credit to Jeroen Baert
 * https://www.forceflow.be/2013/10/07/morton-encodingdecoding-through-bit-interleaving-implementations/
 */

#ifndef MORTON_H
#define MORTON_H

#include <stdint.h>
#include <limits.h>

uint64_t splitBy3(unsigned int a);
uint64_t mortonEncode(unsigned int x, unsigned int y, unsigned int z);

#endif /* MORTON_H */
