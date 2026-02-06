/*
 * Std.h
 *
 * Created: 2/6/2026 6:26:40 PM
 *  Author: Ahmed El Ashiry
 */ 


#ifndef STD_H_
#define STD_H_

typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short int uint16;
typedef signed short int sint16;
typedef unsigned long int uint32;
typedef signed long int sint32;
typedef long long unsigned int uint64;
typedef long long signed int sint64;
typedef long double f128;
typedef double f64;
typedef float f32;

/* NULL pointer definition */
#ifndef NULL_PTR
#define NULL_PTR ((void*)0)
#endif
/*
 * False value definition
 */
#ifndef False
#define False ((uint8)0)
#endif

/*
 * True value definition
 */
#ifndef True
#define True ((uint8)1)
#endif

/*
 * boolean data type definition
 */
typedef unsigned char bool;

/* Logical value declaration */

typedef enum{
	LOW = ((uint8)0), HIGH = ((uint8)1)
}Logical_Value;

#endif

