#include <Arduino.h>

#define KEY_11 27
#define KEY_12 33
#define KEY_13 31
#define KEY_14 49
#define KEY_15 23
#define KEY_16 53
#define KEY_17 51
#define KEY_18 35
#define KEY_19 37
#define KEY_10 39

#define KEY_21 30
#define KEY_22 34
#define KEY_23 36
#define KEY_24 28
#define KEY_25 22
#define KEY_26 24
#define KEY_27 44
#define KEY_28 32
#define KEY_29 26
#define KEY_20 50

#define KEY_31 7
#define KEY_32 8
#define KEY_33 9
#define KEY_34 11
#define KEY_35 4
#define KEY_36 10
#define KEY_37 3
#define KEY_38 12
#define KEY_39 2
#define KEY_30 13

#define KEY_41 PIN_A7
#define KEY_42 19
#define KEY_43 5
#define KEY_44 17
#define KEY_45 16
#define KEY_47 14
#define KEY_48 15
#define KEY_49 18
#define KEY_40 6

#define PRECISION 4

int key[] = {KEY_11, KEY_12, KEY_13, KEY_14, KEY_15, KEY_16, KEY_17, KEY_18, KEY_19, KEY_10,
             KEY_21, KEY_22, KEY_23, KEY_24, KEY_25, KEY_26, KEY_27, KEY_28, KEY_29, KEY_20,
             KEY_31, KEY_32, KEY_33, KEY_34, KEY_35, KEY_36, KEY_37, KEY_38, KEY_39, KEY_30,
             KEY_41, KEY_42, KEY_43, KEY_44, KEY_45, KEY_47, KEY_48, KEY_49, KEY_40};

int kcode[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 10,
               21, 22, 23, 24, 25, 26, 27, 28, 29, 20,
               31, 32, 33, 34, 35, 36, 37, 38, 39, 30,
               41, 42, 43, 44, 45, 47, 48, 49, 40};

int key_count = 39;

#include "DFRobot_LedDisplayModule.h"
DFRobot_LedDisplayModule LEDRight(&Wire, 0xE0);
DFRobot_LedDisplayModule LEDLeft(&Wire, 0xE2);

char str1[10];
char str2[10];
char str[16];

// global key codes 
const int enter_key = 36;
const int plus_key = 40;
const int minus_key = 30;
const int mult_key = 20;
const int div_key = 10;
const int chs_key = 16;
const int square_root_key = 11;
const int exp_e_key = 12;
const int exp_10_key = 13;
const int xpow_key = 14;
const int inv_key = 15;
const int f_key = 42;
const int g_key = 43;
const int del_key = 35;
const int sin_key = 23;
const int cos_key = 24;
const int tan_key = 25;
const int down_key = 33;
const int swap_key = 34;
const int gto_key = 22;

// global mathematical constants
const double e = 2.718281828;
const double pi = 3.141592654;

// global stack variable and precision
static double x = 0;
static double y = 0;
static double z = 0;
static double t = 0;
static double in = 0;
int precision = PRECISION;


bool is_2_operands_key(const int &key) {
  bool is_2_operands = false;
  switch (key)
  {
    case plus_key:
      is_2_operands = true;
      break;
    case minus_key:
      is_2_operands = true;
      break;
    case mult_key:
      is_2_operands = true;
      break;
    case div_key:
      is_2_operands = true;
      break;
    case xpow_key:
      is_2_operands = true;
      break;
    default:
      break;
  }
  return is_2_operands;
}


bool is_1_operand_key(const int &key) {
  bool is_1_operand = false;
  switch (key)
  {
    case square_root_key:
      is_1_operand = true;
      break;
    case exp_e_key:
      is_1_operand = true;
      break;
    case exp_10_key:
      is_1_operand = true;
      break;
    case inv_key:
      is_1_operand = true;
      break;
    case sin_key:
      is_1_operand = true;
      break;
    case cos_key:
      is_1_operand = true;
      break;
    case tan_key:
      is_1_operand = true;
      break;
    case chs_key:
      is_1_operand = true;
      break;
    default:
      break;
  }
  return is_1_operand;
}


int digit_key_value(const int &key)
{
  static const int digit_key[] = {47, 37, 38, 39, 27, 28, 29, 17, 18, 19};
  for (int i = 0; i < 10; i++)
  {
    if (key == digit_key[i])
      return i;
  }
  return -1;
}


bool is_digit_key(const int &key) {
  bool is_digit = false;
  if ( digit_key_value(key) != -1)
    is_digit = true;
  return is_digit;
}


bool is_trigono_key(const int &key) {
  bool is_trigono = false;
  if ( key >= 23 and key <= 25)
    is_trigono = true;
  return is_trigono;
}


void ledPrint(const int &valueSize, 
              const int &precision,
              const char *buffer, 
              DFRobot_LedDisplayModule &ledPtr)
{
  static char digit[8][3] = { {0,0,0}, 
                              {0,0,0},
                              {0,0,0}, 
                              {0,0,0}, 
                              {0,0,0}, 
                              {0,0,0}, 
                              {0,0,0}, 
                              {0,0,0}};
  int digit_i = valueSize;

  int len = valueSize;
  if (precision > 0)
    len++;

  bool point = false;
  for (int i = len; i >= 0; i--)
  {
    if (buffer[i] == '.')
    {
      point = true;
    }
    else
    {
      if (point)
      {
        point = false;
        digit[digit_i][0] = buffer[i];
        digit[digit_i][1] = '.';
        digit[digit_i][2] = 0;
        digit_i--;
      }
      else
      {
        digit[digit_i][0] = buffer[i];
        digit[digit_i][1] = 0;
        digit_i--;
      }
    }
  }

  switch (valueSize)
  {
  case 1:
    ledPtr.print(digit[0]);
    break;
  case 2:
    ledPtr.print(digit[0], digit[1]);
    break;
  case 3:
    ledPtr.print(digit[0], digit[1], digit[2]);
    break;
  case 4:
    ledPtr.print(digit[0], digit[1], digit[2], digit[3]);
    break;
  case 5:
    ledPtr.print(digit[0], digit[1], digit[2], digit[3], digit[4]);
    break;
  case 6:
    ledPtr.print(digit[0], digit[1], digit[2], digit[3], digit[4], digit[5]);
    break;
  case 7:
    ledPtr.print(digit[0], digit[1], digit[2], digit[3], digit[4], digit[5], digit[6]);
    break;
  case 8:
    ledPtr.print(digit[0], digit[1], digit[2], digit[3], digit[4], digit[5], digit[6], digit[7]);
    break;

  default:
    break;
  }
}


void setLedDisplayArea( const int &valueSize, 
                        DFRobot_LedDisplayModule &ledPtr)
{
  switch (valueSize)
  {
  case 1:
    ledPtr.setDisplayArea(8);
    break;
  case 2:
    ledPtr.setDisplayArea(7, 8);
    break;
  case 3:
    ledPtr.setDisplayArea(6, 7, 8);
    break;
  case 4:
    ledPtr.setDisplayArea(5, 6, 7, 8);
    break;
  case 5:
    ledPtr.setDisplayArea(4, 5, 6, 7, 8);
    break;
  case 6:
    ledPtr.setDisplayArea(3, 4, 5, 6, 7, 8);
    break;
  case 7:
    ledPtr.setDisplayArea(2, 3, 4, 5, 6, 7, 8);
    break;
  case 8:
    ledPtr.setDisplayArea(1, 2, 3, 4, 5, 6, 7, 8);
    break;
  default:
    ledPtr.setDisplayArea();
    break;
  }
}


void setDisplayArea(const int &valueSize)
{
  if (valueSize > 8)
  {
    setLedDisplayArea(8, LEDRight);
    setLedDisplayArea(valueSize - 8, LEDLeft);
    LEDLeft.displayOn();
  }
  else
  {
    setLedDisplayArea(valueSize, LEDRight);
    LEDLeft.displayOff();
  }
}


void display(const double &value)
{
  int valueSize = log10(long(abs(value))) + precision + 1;

  if (value < 0)
    valueSize = valueSize + 1;

  if (value == 0.0)
    valueSize = 1 + precision;
    
  setDisplayArea(valueSize);
  double sh = 1;

  if (valueSize > 8)
  {
    switch (precision)
    {
    case 0:
      sh = 100000000;
      break;
    case 1:
      sh = 10000000;
      break;
    case 2:
      sh = 1000000;
      break;
    case 3:
      sh = 100000;
      break;
    case 4:
      sh = 10000;
      break;
    case 5:
      sh = 1000;
      break;
    case 6:
      sh = 100;
      break;
    case 7:
      sh = 10;
      break;
    default:
      break;
    }
    double d1 = trunc(value / sh);
    double d2 = abs(value - (d1 * sh));
    
    dtostrf(d1, (valueSize - 8), 0, str1);
    dtostrf(d2, 9, precision, str2);

    for (int i = 0; i < 9; i++) {
      if (str2[i] == 0x0)
        break;
      if (str2[i] == ' ') 
        str2[i] = '0';
      if (str2[i] == '-') 
        str2[i] = '0';
    }
    ledPrint((valueSize - 8), 0, str1, LEDLeft);
    ledPrint(8, precision, str2, LEDRight);
  }
  else
  {
    dtostrf(value, valueSize - precision, precision, str2);
    ledPrint(valueSize, precision, str2, LEDRight);
  }
}


void clear_entered( int &digit_incr, 
                    bool &entered, 
                    int &last_digit_i) {
  digit_incr = 0;
  in = 0;
  entered = false;
  last_digit_i = 0;
}


void stack_up()
{
  t = z;
  z = y;
  y = x;
}


void stack_drop()
{
  y = z;
  z = t;
}


void stack_roll_up()
{
  double temp = t;
  t = z;
  z = y;
  y = x;
  x = temp;
}


void stack_roll_down()
{
  double temp = x;
  x = y;
  y = z;
  z = t;
  t = temp;
}


void swap_xy()
{
  double temp = x;
  x = y;
  y = temp;
}

// operations with 2 operands
void plus     (const double &a, const double &b)  { Serial.println(__func__); x = a + b; }  
void minus    (const double &a, const double &b)  { Serial.println(__func__); x = a - b; }
void divide   (const double &a, const double &b)  { Serial.println(__func__); x = a / b; }
void mult     (const double &a, const double &b)  { Serial.println(__func__); x = a * b; }
void xpow     (const double &a, const double &b)  { Serial.println(__func__); x = pow(a, b); }
void percent  (const double &a, const double &b)  { Serial.println(__func__); x = a * (b / 100); }
void dpercent (const double &a, const double & b) { Serial.println(__func__); x = ((b - a) / a) * 100; }
void noop_2   (const double &a, const double &b) { Serial.println(__func__); }

// operations with 1 operand
void square           (const double &a) { Serial.println(__func__); x = sq(a); }
void square_root      (const double &a) { Serial.println(__func__); x = sqrt(a); }
void log_e            (const double &a) { Serial.println(__func__); x = log(a); }
void exp_e            (const double &a) { Serial.println(__func__); x = pow(e, a); }
void log_10           (const double &a) { Serial.println(__func__); x = log10(a); }
void exp_10           (const double &a) { Serial.println(__func__); x = pow(10.0, a); }
void inv              (const double &a) { Serial.println(__func__); x = 1 / a; }
void sine             (const double &a) { Serial.println(__func__); x = sin(x); }
void cosine           (const double &a) { Serial.println(__func__); x = cos(x); }
void tangent          (const double &a) { Serial.println(__func__); x = tan(x); }
void arcsine          (const double &a) { Serial.println(__func__); x = asin(x); }
void arccosine        (const double &a) { Serial.println(__func__); x = acos(x); }
void arctangent       (const double &a) { Serial.println(__func__); x = atan(x); }
void hypersine        (const double &a) { Serial.println(__func__); x = sinh(x); }
void hypercosine      (const double &a) { Serial.println(__func__); x = cosh(x); }
void hypertangent     (const double &a) { Serial.println(__func__); x = tanh(x); }
void hyperarcsine     (const double &a) { Serial.println(__func__); x = log(x + sqrt(sq(x) + 1)); }
void hyperarccosine   (const double &a) { Serial.println(__func__); x = log(x + sqrt(sq(x) - 1)); }
void hyperarctangent  (const double &a) { Serial.println(__func__); x = log((1 + x) / (1 - x)) / 2; }
void noop_1           (const double &a) { Serial.println("Operation not defined. Please fix the bug!"); }

void process_key(const int &key, 
                  bool &f_pressed, 
                  bool &g_pressed, 
                  bool &entered, 
                  bool &fix_selected, 
                  bool &hyp_selected,
                  bool &hyp_arc_selected,
                  bool &gto_selected,
                  int *last_digit_key,
                  int &last_digit_i,
                  int &digit_incr) 
{
  // GTO (HYP / HYP^-1) key 
  // ----------------------
  if (key == gto_key) {
    if (f_pressed) {
      // Hperbolic - Trig functions
      f_pressed = false;
      hyp_selected = true;
    } 
    else if (g_pressed) {
      // Hyperbolic Arc - Trig functions
      g_pressed = false;
      hyp_arc_selected = true;
    }
    else {
      // goto operation
      gto_selected = true;
    }
  }

  //    Digit key pressed
  //    -----------------
  else if (is_digit_key(key))
  {
    Serial.print("digit entered = ");
    Serial.println(digit_key_value(key));

    // after fix prefix
    if (fix_selected)
    {
      fix_selected = false;
      precision = digit_key_value(key);
      if (precision > 7)
        precision = 7;
 
      if (entered)
        display(in);
      else
        display(x);

      // after f prefix
    }
    else if (f_pressed and digit_key_value(key) == 7)
    {
      f_pressed= false;
      fix_selected = true;

    }
    // without prefix
    else
    {
      if (last_digit_i < 9)
      {
        last_digit_key[last_digit_i] = digit_key_value(key);
        last_digit_i++;
      }
      else
      {
        for (last_digit_i = 0; last_digit_i < 9; last_digit_i++)
        {
          last_digit_key[last_digit_i] = last_digit_key[last_digit_i + 1];
        }
        last_digit_key[last_digit_i] = digit_key_value(key);
      }
      if ( __FLT_MAX__ - digit_key_value(key) < in * digit_incr) {
        in = __FLT_MAX__;
      } else {
        in = in * digit_incr + digit_key_value(key);
        digit_incr = 10;
      }
      entered = true;
      display(in);
    }
  }

  //    enter key pressed
  //    -----------------
  else if (key == enter_key)
  {
    if (entered)
      x = in;
    stack_up();
    clear_entered(digit_incr, 
                  entered, 
                  last_digit_i);
    display(x);
  }

  // 2 operands operations with stack drop
  // -------------------------------------
  else if (is_2_operands_key(key)) {
    void (*oper)(const double&, const double&) = noop_2;
    switch (key)
    {
      case plus_key:
        oper = plus;
        break;
      case minus_key:
        oper = minus;
        break;
      case div_key:
        oper = divide;
        break;
      case mult_key:
        oper = mult;
        break;
      case xpow_key:
        if (g_pressed) {
          g_pressed = false;
          oper = percent;
        }
        else
          oper = xpow;
        break;
      default:
        break;
    }
    if (entered) {
      oper(x, in);
      clear_entered(digit_incr, 
                    entered, 
                    last_digit_i);
    }
    else
      oper(y, x);
    stack_drop();
    display(x);
  }

  // 2 operands operations under (g_pressed) a 1 operand operation key and no stack drop
  // -----------------------------------------------------------------------------------
  else if (g_pressed and key == inv_key) {
    g_pressed = false;
    if (entered) {
      dpercent(x, in);
      clear_entered(digit_incr, 
                    entered, 
                    last_digit_i);
    }
    else
      dpercent(y, x);
    display(x);
  }

  // 1 operand operations (without stack drop)
  // -----------------------------------------
  else if (is_1_operand_key(key)) {
    void (*oper)(const double&) ;
    if (is_trigono_key(key) and hyp_arc_selected) {
      hyp_arc_selected = false;
      switch (key)
      {
      case sin_key:
        oper = hyperarcsine;
        break;
      case cos_key:
        oper = hyperarccosine;
        break;
      case tan_key:
        oper = hyperarctangent;
        break;
      default:
        break;
      }
    } else if (is_trigono_key(key) and hyp_selected) {
      hyp_selected = false;
      switch (key)
      {
      case sin_key:
        oper = hypersine;
        break;
      case cos_key:
        oper = hypercosine;
        break;
      case tan_key:
        oper = hypertangent;
        break;
      default:
        break;
      }
    } else if (is_trigono_key(key) and g_pressed) {
      g_pressed = false;
      switch (key)
      {
      case sin_key:
        oper = arcsine;
        break;
      case cos_key:
        oper = arccosine;
        break;
      case tan_key:
        oper = arctangent;
        break;
      default:
        break;
      }
    } else if (is_trigono_key(key)) {
      switch (key)
      {
      case sin_key:
        oper = sine;
        break;
      case cos_key:
        oper = cosine;
        break;
      case tan_key:
        oper = tangent;
        break;
      default:
        break;
      }
    }
    else if (g_pressed) {
      g_pressed = false;
      switch (key)
      {
        case square_root_key:
          oper = square;
          break;
        case exp_e_key:
          oper = log_e;
          break;
        case exp_10_key:
          oper = log_10;
          break;
        default:
          break;
      }
    } else {
      switch (key)
      {
        case square_root_key:
          oper = square_root;
          break;
        case exp_e_key:
          oper = exp_e;
          break;
        case exp_10_key:
          oper = exp_10;
          break;
        case inv_key:
          oper = inv;
          break;
        default:
          break;
      }
    }
    if (entered) { 
      oper(in);
      clear_entered(digit_incr, 
                    entered, 
                    last_digit_i);
    }
    else
      oper(x);
    display(x);
  }

  //    +/- key pressed
  //    ---------------
  else if (key == chs_key)
  {
    // abs(x)
    if (g_pressed)
    {
      g_pressed = false;
      if (entered)
      {
        in = abs(in);
        display(in);
      }
      else
      {
        x = abs(x);
        display(x);
      }

    // +/- (CHS)
    }
    else
    {
      if (entered)
      {
        if (in != 0)
        {
          in = in * -1;
          display(in);
        }
      }
      else
      {
        if (x != 0)
        {
          x = x * -1;
          display(x);
        }
      }
    }
  }

  //    down key pressed
  //    ----------------
  else if (key == down_key)
  {
    // stack roll up
    if (g_pressed)
    {
      g_pressed = false;
      if (entered)
        x = in;
      stack_roll_up();
      clear_entered(digit_incr, 
                    entered, 
                    last_digit_i);
      display(x);

      // stack roll down
    }
    else
    {
      if (entered)
        x = in;
      stack_roll_down();
      clear_entered(digit_incr, 
                    entered, 
                    last_digit_i);
      display(x);
    }
  }

  //    swap key pressed
  //    ----------------
  else if (key == swap_key)
  {
    // clear x 
    if (g_pressed)
    {
      g_pressed = false;
      if (entered) 
        clear_entered(digit_incr, 
                      entered, 
                      last_digit_i);
      x = 0;
      display(x);

    // swap xy
    }
    else
    {
      if (entered) {
        x = in;
        clear_entered(digit_incr, 
                      entered, 
                      last_digit_i);
      }
      swap_xy();
      display(x);
    }
  }
}


void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < key_count; i++)
  {
    pinMode(key[i], INPUT);
  }


  while (LEDRight.begin(LEDRight.e8Bit) != 0)
  {
    Serial.println("FaiLEDRight to initialize the chip , please confirm the chip connection!");
    delay(1000);
  }
  LEDRight.setDisplayArea();
  LEDRight.displayOff();


  while (LEDLeft.begin(LEDLeft.e8Bit) != 0)
  {
    Serial.println("FaiLEDRight to initialize the chip , please confirm the chip connection!");
    delay(1000);
  }
  LEDLeft.setDisplayArea();
  LEDLeft.displayOff();

  LEDRight.displayOn();
  display(x);
}

void loop()
{
  // last entered digits 10 power increment 
  static int last_digit_key[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  static int last_digit_i = 0;
  static int digit_incr = 0;

  // enter and key mode 
  static bool entered = false;
  static bool f_pressed = false;
  static bool g_pressed = false;
  static bool fix_selected = false;
  static bool hyp_selected = false;
  static bool hyp_arc_selected = false;
  static bool gto_selected = false;

  // current pressed key
  static int pressed_key = 0;

  // find pressed_key
  // ----------------
  pressed_key = 0;
  for (int i = 0; i < key_count; i++)
  {
    if (digitalRead(key[i]) == HIGH)
    {
      if (kcode[i] == 41)
      {
        setup();
        break;
      }
      pressed_key = kcode[i];
      delay(100);
      break;
    }
  }

  //    alternate (f) key pressed
  //    -------------------------
  if (pressed_key == f_key)
  {
    f_pressed = true;
  }

  //    alternate (g) ley pressed
  //    -------------------------
  else if (pressed_key == g_key)
  {
    g_pressed = true;
  }

  //    del key pressed
  //    ---------------
  else if (pressed_key == del_key)
  {
    if (entered && last_digit_i > 0)
    {
      in = round((in - last_digit_key[last_digit_i]) / digit_incr);
      last_digit_i--;
      display(in);
    }
    else
    {
      entered = false;
      in = 0;
      x = in;
      display(x);
    }
  } else if (pressed_key != 0) {
    Serial.print("pressed key = ");
    Serial.println(pressed_key);

    process_key(pressed_key, 
                f_pressed, 
                g_pressed, 
                entered, 
                fix_selected,
                hyp_selected,
                hyp_arc_selected,
                gto_selected, 
                last_digit_key, 
                last_digit_i, 
                digit_incr); 

    Serial.print("t = ");
    Serial.println(t);
    Serial.print("z = ");
    Serial.println(z);
    Serial.print("y = ");
    Serial.println(y);
    Serial.print("x = ");
    Serial.println(x);
    if (entered) {
      Serial.print("in = ");
      Serial.println(in);
    }
    Serial.println("--------------------------------------------");
  }
  // wait 1/10 seconds for next key press
  delay(100);
}