/*
 * Macros.h
 *
 * Created: 2/6/2026 6:26:10 PM
 *  Author: Ahmed El Ashiry
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define BIT_SET(REG,BIT)	(REG |=(1U<<BIT))
#define BIT_CLR(REG,BIT)	(REG &= ~(1U<<BIT))
#define BIT_TGL(REG,BIT)	(REG ^= (1U<<BIT))
#define BIT_GET(REG,BIT)	(1U & (REG>>BIT))
#define BIT_IS_CLR(REG,BIT)	(!(REG &(1U<<BIT)))
#define BIT_IS_SET(REG,BIT)	(REG & (1U<<BIT))
#define ROR(REG,NUM)		((REG>>NUM)|(REG<<(8U-NUM)))
#define ROL(REG,NUM)		((REG<<NUM)|(REG>>(8U-NUM)))


#endif /* MACROS_H_ */