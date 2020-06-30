//
//    FILE: float2double.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.0
// PURPOSE: experimental expands a float in a IEEE 754 double to be printed to PC.
//

#include <IEEE754tools.h>

byte x[8];

void setup()
{
  Serial.begin(115200);

  test1();
  test2();
  test3();
  test4();

  Serial.println("done");
}

void test1()
{
  Serial.println();
  for (float f = -50.0; f < 50.0; f += 10.0)
  {
    dumpFloat(f);
    float2DoublePacked(f, x, LSBFIRST);
    dumpByteArray(x);
    float g = doublePacked2Float(x, LSBFIRST);
    Serial.println(g, 10);
    if (f != g) Serial.println("-- FAIL --");
    Serial.println();
  }
}

void test2()
{
  Serial.println("\n0.15625");
  dumpFloat(0.15625);
  //     sign = 0
  // exponent = 7C
  // mantissa = 0020 0000
}

void test3()
{
  Serial.println("\nPI-check");
  Serial.println(PI, 20);
  float2DoublePacked(PI, x);
  dumpByteArray(x);
  float f = doublePacked2Float(x, LSBFIRST);
  Serial.println(f, 20);
  Serial.println();
}

void test4()
{
  Serial.println("\nBIG-check");
  Serial.println(1.23456789e38, 20);
  dumpFloat(1.23456789e38);
  float2DoublePacked(1.23456789e38, x);
  dumpByteArray(x);
  float f = doublePacked2Float(x, LSBFIRST);
  Serial.println(f / 1e38, 20);          // divide prevents ovf in output
  dumpFloat(f);
  Serial.println();
}


void loop()
{
}








void dumpByteArray(byte *ar)
{
  for (int i = 0; i < 8; i++)
  {
    if (ar[i] < 0x10) Serial.print('0');
    Serial.print(ar[i], HEX);
    Serial.print('\t');
  }
  Serial.println();
}
