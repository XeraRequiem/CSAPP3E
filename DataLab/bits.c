/* 
 * CS:APP Data Lab 
 * 
 * Jon Spitzer (Xera)
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */



/* int test_dl10(int parameter1, int parameter2)
 * {
 *   int result = 0;
 *   int i;
 *   for (i = parameter2; i <= parameter1; i++)
 *   result |= 1 << i;
 *   return result;
 *  } 
 */

//Sets bits between low and high (inclusive) to 1
int dl10(int highbit, int lowbit) {
   int high = 1 << highbit; //highest bit to 1
   int high2 = high + ~0;
   int high3 = (high2 << 1) + 1;
   return (high3) & ~((1 << lowbit) + ~0); //sets lower bits to 0
}


/*   int test_dl11(int x, int y)
 *   {
 *       return ~(x|y);
 *   }
 */

//De Morgan's Law
int dl11(int x, int y) {
  return ~x & ~y;
}


/* int test_dl12(int x, int y)
 * {
 *    return x|y;
 * }
 */

//De Morgan's Law
int dl12(int x, int y) {
   return ~(~x & ~y);
}


/*  int test_dl13(int x) {
 *     int result = 0;
 *     int i;
 *     for (i = 0; i < 32; i++)
 *     result ^=  (x >> i) & 0x1;
 *     return result; 
 *  }
 */

//Fold into itself
//Tests for odd number of 1's
int dl13(int x) {
   x ^= x >> 16;
   x ^= x >> 8;
   x ^= x >> 4;
   x ^= x >> 2;
   x ^= x >> 1;
   return x &= 1; 
}

/*int test_dl14(int x, int y) {
 *   return x^y; 
 *}
 */

//bitwise xor
int dl14(int x, int y) {
   return ~(x & y) & ~(~x & ~y);
}

 
/* assuming a little endiamachine 
 * least significant byte stored first 
 *
 * int test_dl15(int x, int n, int m)
 * {
 *
 *   unsigned int nmask, mmask;
 *
 *   switch(n) {
 *   case 0:
 *     nmask = x & 0xFF;
 *     x &= 0xFFFFFF00;
 *     break;
 *   case 1:
 *     nmask = (x & 0xFF00) >> 8;
 *     x &= 0xFFFF00FF;
 *     break;
 *   case 2:
 *     nmask = (x & 0xFF0000) >> 16;
 *     x &= 0xFF00FFFF;      
 *     break;
 *   default:
 *     nmask = ((unsigned int)(x & 0xFF000000)) >> 24;
 *     x &= 0x00FFFFFF;
 *     break;
 *    }
 *
 *   switch(m) {
 *   case 0:
 *     mmask = x & 0xFF;
 *     x &= 0xFFFFFF00;
 *     break;
 *   case 1:
 *     mmask = (x & 0xFF00) >> 8;
 *     x &= 0xFFFF00FF;
 *     break;
 *   case 2:
 *     mmask = (x & 0xFF0000) >> 16;
 *     x &= 0xFF00FFFF;      
 *     break;
 *   default:
 *     mmask = ((unsigned int)(x & 0xFF000000)) >> 24;
 *     x &= 0x00FFFFFF;
 *     break;
 *   }
 *
 *   nmask <<= 8*m;
 *   mmask <<= 8*n;
 *
 *   return x | nmask | mmask;
 * }
 */
int dl15(int x, int n, int m) {
   int nShift; //n bytes left
   int mShift; //m bytes left
   int nmask;
   int mmask;
    
   nShift = n << 3; //Shift by bytes
   mShift = m << 3; //Shift by bytes

   nmask = ((x & (0xFF << nShift)) >> nShift) & 0xFF; //Move desired byte to lower bits & zero rest
   x &= ~(0xFF << nShift);

   mmask = ((x & (0xFF << mShift)) >> mShift) & 0xFF; //Move desired byte to lower bits & zero rest
   x &= ~(0xFF << mShift);

   nmask <<= mShift;
   mmask <<= nShift;

   return x | nmask | mmask; //swaps bytes
}


/*int test_dl16(int x, int y, int z)
 * {
 *   return x?y:z;
 * }
 */
int dl16(int x, int y, int z) {
   int num = !!x; // 0 or nonzero
   int mask = ~num + 0x1; //0(a=0), -1(a=1)
   return (y & mask) + (z & (~0 + num)); //return either y or z
}


/*  int test_dl17(int x)
 *  {
 *   return (x & 0x1) ? -1 : 0;
 *  }
 */
int dl17(int x) {
   return ~(x & 0x1) + 1;
}


/* int test_dl18(int x, int n)
 * {
 *    int p2n = 1<<n;
 *    return x/p2n;	
 * }
 */

int dl18(int x, int n) {
   int sign = (x >> 31) & 0x1; //signbit
   x += ((sign << n) + (~sign + 1)); //offset
   return x >> n;
}


/*  int test_dl19(void) {
 *  int result = 0;
 *  int i;
 *  for (i = 0; i < 32; i+=2)
 *    result |= 1<<i;
 *  return result; }
 */

int dl19(void) {
   // 01010101 01010101 01010101 01010101
   int mask = 0x55;
   int mask2 = (mask << 8) | mask;
   return (mask2 << 16) | mask2; //0x55555555
}


/*   int dl1(int x) {return (x < 0) ? -x : x; }*/

//Absolute Value(x)
int dl1(int x) {
   int sign = x >> 31; //Signbit
   return (x ^ sign) + (~sign + 1);
}


/*   int test_dl20(int x)
 *   {
 *      return (x*3)/4;
 *   }
 */

// (3x)/4
int dl20(int x) {
   int ls = x + x + x; //3x
   int sign  = (ls >> 31) & 0x1;
   ls+= (sign << 2) + (~sign + 1);//offset
   return ls >> 2;
}


/* unsigned test_dl21(unsigned uf) {
 * 	float f = u2f(uf);
 * 	float hf = 0.5*f;
 * 	if (isnan(f))
 *   	    return uf;
 * 	else
 *   	    return f2u(hf);
 * }
 */
unsigned dl21(unsigned x) {
   int sign, exp, maskExp, maskMan, maskSign, round;

   maskSign = 0x80000000;
   maskExp = 0x7F800000;
   maskMan = 0x7FFFFF;

   round = !((x & 0x3) ^ 0x3);

   exp = (x & maskExp) >> 23;
   sign = x & (1 << 31);

   //NaN/Infinity
   if (exp == 0xFF) return x;
  
   //Border
   if (exp == 1){
      return sign | (round + ((x & (maskMan + maskExp)) >> 1));
   }

   //Denormalized
   if (exp == 0) {
      int temp = (x & maskMan) >> 1;
      return sign | (temp + round);
   }

   //Normalized
   return ((exp - 1) << 23) | (x & (maskMan + maskSign));
}


/* unsigned test_dl22(int x) {
 *    float f = (float) x;
 *    return f2u(f);
 * }
 */
unsigned dl22(int x) {
   int sign;
   int exponent;
   unsigned int absX;
   unsigned int mantissa;


   if (x == 0) {
      return 0; // special case
   }

   //Store sign bit
   sign = 0;
   absX = x;

   if (x < 0) {
      sign = 1 << 31;       
      absX = ~x + 1; 
   }

   //Shift the input left until the mantissa is formed.
   //Form exponent by subtracting the number of shifts from 158.
   exponent = 158;

   while (!(absX & 0x80000000)) {
      exponent--;
      absX <<= 1;
   }

   //Compute mantissa
   mantissa = absX >> 8;
   
   //Rounding Correction
   if((absX & 0xFF) > 0x80 || (((absX & 0xFF) == 0x80) && ((absX >> 8) & 1))) {
      mantissa++;
      if (mantissa >= 0x1000000) {
         mantissa >>= 1;
         exponent++;
      }
   }

   return sign | (exponent << 23) | (mantissa & 0x7fffff);
}



/* unsigned test_dl23(unsigned uf) {  
 *  float f = u2f(uf);
 *  float tf = 2*f;
 *  if (isnan(f))
 *    return uf;
 *  else
 *    return f2u(tf);
 * }
 */
unsigned dl23(unsigned x) {
   int maskMan;
   unsigned sign, exp, man;
 
   maskMan = 0x7FFFFF;

   sign = x & 0x80000000;
   exp = (x >> 23) & 0xFF;
   man = x & maskMan;
 
   //Nan/Infinity or 0
   if (exp == 0xFF || (exp == 0 && man == 0))
      return x; 

   //Normalized = Increment exponent   
   //Denormalized = double fraction
   //Border = Decrement mantissa, increment exponent
   if (exp) {
      exp++;
   } else if (man == maskMan) {
      man--;
      exp++;
   } else {
      man <<= 1;
   }

   return sign | (exp << 23) | man;
}


/*dl24 - return the minimum number of bits required to represent x in
 *             two's complement
 * int test_dl24(int x) {
 *   unsigned int a, cnt;
 *   
 *   x = x<0 ? -x-1 : x;
 *   a = (unsigned int)x;
 *   for (cnt=0; a; a>>=1, cnt++)
 *       ;
 *   return (int)(cnt + 1);
 * }
 */

//Count leading 1's or 0's
int dl24(int x) {
   int mask1; //0x55555555
   int mask2; //0x33333333
   int mask3; //0x0F0F0F0F
   int mask4; //0x00FF00FF
   int mask5; //0x0000FFFF

   mask1 = 0x55 | (0x55 << 8);
   mask1 |= (mask1 << 16);
   
   mask2 = 0x33 | (0x33 << 8);
   mask2 |= (mask2 << 16);
   
   mask3 = 0x0F | (0x0F << 8);
   mask3 |= (mask3 << 16);
   
   mask4 = 0xFF | (0xFF << 16);
 
   mask5 = 0xFF | (0xFF << 8);

   x ^= (x>>31); //Converts negative to positive
 
   //Fold into self
   x |= x>>1;
   x |= x>>2;
   x |= x>>4;
   x |= x>>8;
   x |= x>>16;

   x = (x & mask1) + ((x >> 1) & mask1); 
   x = (x & mask2) + ((x >> 2) & mask2); 
   x = (x + (x >> 4)) & mask3; 
   x = (x + (x >> 8)) & mask4; 
   x = (x + (x >> 16)) & mask5; 

   return x+1;
}


/*   int test_dl2(int x, int y) { 
 *      long long lsum = (long long) x + y;
 *      return lsum == (int) lsum;
 *   }
 */

//Checks overflow
int dl2(int x, int y) {
   int xn = x >> 31 & 1;
   int yn = y >> 31 & 1;
   int sn = ((x + y) >> 31) & 1;
   int pf = (xn ^ yn); //0 = no overflow
   int of = (xn ^ sn); //0 = overflow
   return pf | !of;
}


/*    int test_dl3(int x) {
 *    int i;
 *    for (i = 0; i < 32; i+=2)
 *       if ((x & (1<<i)) == 0)
 *	  return 0;
 *    return 1; }
 */

//Checks if every even bit is 1
int dl3(int x) {
   int mask = 0x55;//even bits are 1
   int rs1 = x & mask;
   int rs2 = (x >> 8) & rs1;
   int rs3 = (x >> 16) & rs2;
   int rs4 = (x >> 24) & rs3;
   int cumm = rs4 & mask;
   return !(cumm ^ mask);
}


/*   int test_dl4(int x) {
 *   int i;
 *   for (i = 1; i < 32; i+=2)
 *     if ((x & (1<<i)) == 0)
 *	  return 0;
 *    return 1; }
 */

//Checks if every odd bit is 1
int dl4(int x) {
   int mask = 0xAA; //odd bits are 1
   int rs1 = x & mask;
   int rs2 = (x >> 8) & rs1;
   int rs3 = (x >> 16) & rs2;
   int rs4 = (x >> 24) & rs3;
   int cumm = rs4 & mask;
   return !(cumm ^ mask);
}

 
/*   int test_dl5(int x) {
 *   int i;
 *   for (i = 0; i < 32; i+=2)
 *     if (x & (1<<i))
 *	  return 1;
 *   return 0; }
 */

//Checks if any even bit is 1
int dl5(int x) {
   int mask;

   mask = 0x55 + (0x55 << 8);
   mask |= (mask << 16);
   return !(!(x & mask));
}
 

/*  int test_dl6(int x) {
 *   int i;
 *   for (i = 1; i < 32; i+=2)
 *       if (x & (1<<i))
 *	     return 1;
 *   return 0; }
 */

//Checks if any odd bit is 1
int dl6(int x) {
   int mask;

   mask = 0xAA + (0xAA << 8);
   mask |= (mask << 16);
   return !(!(x & mask));
}

 
/*   int test_dl7(int x)
 *   {
 *      return !x;
 *   }
 *
 *   Legal ops: ~ & ^ | + >>
 *   Max ops: 10
 *   Rating: 4 
 */

int dl7(int x) {
   //Checks if negative or positive
   return ((x >> 31) | ((~x + 1) >> 31)) + 1; 
}

 
/*   int test_dl8(int x, int y)
 *   {
 *      return x&y;
 *   }
 */

//DeMorgan's Law
int dl8(int x, int y) {
   return ~(~x | ~y);
}


/*   int test_dl9(int x) {
 *      int result = 0;
 *      int i;
 *      for (i = 0; i < 32; i++)
 *         result +=  (x >> i) & 0x1;
 *      return result;
 *   }
 */

//Split into 2 segments and fold individually
//Hamming Weight
int dl9(int x) {
   int mask;
   int mask2;
   int mask3;
   int mask4;
   int mask5;
   
   //Puts bit count into lower bits
   mask = 0x55 + (0x55 << 8);  //01010101
   mask |= (mask << 16);
 
   mask2 = 0x33 + (0x33 << 8); //00110011
   mask2 |= (mask2 << 16);

   mask3 = 0x0F + (0x0F << 8); //00001111
   mask3 |= (mask3 << 16);
 
   mask4 = 0xFF + (0xFF << 16);

   mask5 = 0xFF + (0xFF << 8);
 
   x = (x & mask) + ((x >> 1) & mask);
   x = (x & mask2) + ((x >> 2) & mask2);
   x = (x & mask3) + ((x >> 4) & mask3);
   x = (x & mask4) + ((x >> 8) & mask4);
   x = (x & mask5) + ((x >> 16) & mask5);

   return x;
}
