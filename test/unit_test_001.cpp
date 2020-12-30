//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-03
// PURPOSE: unit tests for the IEEE754tools.h
//          https://github.com/RobTillaart/IEEE754tools
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
// #define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
// #define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "IEEE754tools.h"



unittest_setup()
{
}

unittest_teardown()
{
}

/*
unittest(test_new_operator)
{
  assertEqualINF(exp(800));
  assertEqualINF(0.0/0.0);
  assertEqualINF(42);
  
  assertEqualNAN(INFINITY - INFINITY);
  assertEqualNAN(0.0/0.0);
  assertEqualNAN(42);
}
*/

unittest(test_all)
{
  fprintf(stderr, "VERSION: %s\n", IEEE754_VERSION);

  fprintf(stderr, "Convert PI to double and back\n");
  uint8_t ar[8];
  float p = PI;
  float2DoublePacked(p, ar);
  float q = doublePacked2Float(ar);
  assertEqualFloat(p, q, 0.0001);

  fprintf(stderr, "IEEE_NAN\n");
  assertTrue(IEEE_NAN(0.0 / 0.0));

  fprintf(stderr, "IEEE_INF\n");
  assertEqual(1,  IEEE_INF(exp(800)));
  assertEqual(-1, IEEE_INF(-exp(800)));
  assertEqual(0,  IEEE_INF(PI));

  fprintf(stderr, "IEEE_PosINF\n");
  assertTrue(IEEE_PosINF(exp(800)));

  fprintf(stderr, "IEEE_NegINF\n");
  assertTrue(IEEE_NegINF(-exp(800)));

  fprintf(stderr, "IEEE_Sign\n");
  assertTrue(IEEE_Sign(PI));
  assertTrue(IEEE_Sign(-PI));

  fprintf(stderr, "IEEE_Exponent\n");
  assertTrue(IEEE_Exponent(PI));

  fprintf(stderr, "IEEE_Mantisse\n");
  assertTrue(IEEE_Mantisse(PI));

  fprintf(stderr, "IEEE_POW2\n");
  for (int i = 0; i < 20; i++)
  {
    fprintf(stderr, "%s\t", i);
    assertEqualFloat(pow(2, i), IEEE_POW2(2, i), 0.0001);
  }

  fprintf(stderr, "IEEE_POW2fast\n");
  for (int i = 0; i < 20; i++)
  {
    fprintf(stderr, "%s\t", i);
    assertEqualFloat(pow(2, i), IEEE_POW2fast(2, i), 0.0001);
  }



}

unittest_main()

// --------
