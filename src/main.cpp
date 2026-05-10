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
#define IS_LEFT_ALIGNED true

int key_count = 39;

int key[] = {KEY_11, KEY_12, KEY_13, KEY_14, KEY_15, KEY_16, KEY_17, KEY_18, KEY_19, KEY_10,
             KEY_21, KEY_22, KEY_23, KEY_24, KEY_25, KEY_26, KEY_27, KEY_28, KEY_29, KEY_20,
             KEY_31, KEY_32, KEY_33, KEY_34, KEY_35, KEY_36, KEY_37, KEY_38, KEY_39, KEY_30,
             KEY_41, KEY_42, KEY_43, KEY_44, KEY_45,         KEY_47, KEY_48, KEY_49, KEY_40};

int kcode[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 10,
               21, 22, 23, 24, 25, 26, 27, 28, 29, 20,
               31, 32, 33, 34, 35, 36, 37, 38, 39, 30,
               41, 42, 43, 44, 45,     47, 48, 49, 40};

// op key code (hyp sin/cos/tan = + 100)
const int op_sqrt       = 11;
const int op_exp_e      = 12;
const int op_exp_10     = 13;
const int op_xpow       = 14;
const int op_inv        = 15;
const int op_chs        = 16;
const int op_7          = 17;
const int op_8          = 18;
const int op_9          = 19; 
const int op_div        = 10;

const int op_sst        = 21;
const int op_gto        = 22;
const int op_sin        = 23;
const int op_cos        = 24;
const int op_tan        = 25;
const int op_hyp_sin    = 123;
const int op_hyp_cos    = 124;
const int op_hyp_tan    = 125;
const int op_eex        = 26;
const int op_4          = 27;
const int op_5          = 28;
const int op_6          = 29;
const int op_mult       = 20;

const int op_rs         = 31;
const int op_gsb        = 32;
const int op_down       = 33;
const int op_swap_y_x   = 34;
const int op_del        = 35;
const int op_enter      = 36;
const int op_1          = 37;
const int op_2          = 38;
const int op_3          = 39;
const int op_minus      = 30;

const int op_on         = 41;
const int op_f          = 42;
const int op_g          = 43;
const int op_sto        = 44;
const int op_rcl        = 45;
const int op_0          = 47;
const int op_dp         = 48;
const int op_stat_plus  = 49;
const int op_plus       = 40;

// op g key codes (= op key code + 40, hyp inv + 100)
const int op_sq         = 51;
const int op_log_e      = 52;
const int op_log_10     = 53;
const int op_percent    = 54;
const int op_dpercent   = 55;
const int op_abs        = 56;
const int op_deg        = 57;
const int op_rad        = 58;
const int op_grad       = 59; 
const int op_le         = 50;

const int op_bst        = 61;
const int op_hyp_inv    = 62;
const int op_sin_inv    = 63;
const int op_cos_inv    = 64;
const int op_tan_inv    = 65;
const int op_hyp_sin_inv = 163;
const int op_hyp_cos_inv = 164;
const int op_hyp_tan_inv = 165;
const int op_pi         = 66;
const int op_sf         = 67;
const int op_cf         = 68;
const int op_gf         = 69;
const int op_e0         = 60;

const int op_pr         = 71;
const int op_rtn        = 72;
const int op_up         = 73;
const int op_rnd        = 74;
const int op_clx        = 75;
const int op_lstx       = 76;
const int op_2pol       = 77;
const int op_2dec       = 78;
const int op_2deg       = 79;
const int op_test       = 70;

const int op_const_conv = 81;
//const int op_f          = 82;
//const int op_g          = 83;
const int op_int        = 84;
const int op_mem        = 85;
const int op_mean       = 87;
const int op_stdv       = 88;
const int op_stat_minus = 89;
const int op_comb       = 80;

// op f key code (= op key code * -1)
const int op_a          = -11;
const int op_b          = -12;
const int op_c          = -13;
const int op_d          = -14;
const int op_e          = -15;
const int op_matrix     = -16;
const int op_fix        = -17;
const int op_sci        = -18;
const int op_eng        = -19; 
const int op_solve      = -10;

const int op_lbl        = -21;
const int op_hyp        = -22;
const int op_dim        = -23;
const int op_ind_i      = -24;
const int op_i          = -25;
const int op_result     = -26;
const int op_swap_x     = -27;
const int op_dse        = -28;
const int op_isg        = -29;
const int op_inegrate   = -20;

const int op_pse        = -31;
const int op_clstat     = -32;
const int op_clprgm     = -33;
const int op_clreg      = -34;
const int op_clprefix   = -35;
const int op_random     = -36;
const int op_2rect      = -37;
const int op_2min       = -38;
const int op_2rad       = -39;
const int op_swqp_re_im = -30;

const int op_setup_keys = -41;
//const int op_f          = -42;
//const int op_g          = -43;
const int op_frac       = -44;
const int op_user       = -45;
const int op_fact       = -47;
const int op_lin_est    = -48;
const int op_lin_reg    = -49;
const int op_perm       = -40;

// global mathematical constants
const double e  = 2.718281828;
const double pi = 3.141592654;


#include "DFRobot_LedDisplayModule.h"
DFRobot_LedDisplayModule LEDRight(&Wire, 0xE0);
DFRobot_LedDisplayModule LEDLeft(&Wire, 0xE2);

char str1[10];
char str2[10];
char str[16];

// global stack variable and precision
double x  = 0;
double y  = 0;
double z  = 0;
double t  = 0;
double in = 0;
int precision = PRECISION;

// left or right aligned display
bool is_left_aligned = IS_LEFT_ALIGNED;

bool is_2_operands_op(const int& op_code)
{
    bool is_2_operands = false;
    switch (op_code)
    {
        case op_div:
            is_2_operands = true;
            break;
        case op_mult:
            is_2_operands = true;
            break;
        case op_minus:
            is_2_operands = true;
            break;
        case op_plus:
            is_2_operands = true;
            break;
        case op_comb:
            is_2_operands = true;
            break;
        case op_perm:
            is_2_operands = true;
            break;
        case op_xpow:
            is_2_operands = true;
            break;
        case op_percent:
            is_2_operands = true;
            break;
        case op_dpercent:
            is_2_operands = true;
            break;
        default:
            break;
    }
    return is_2_operands;
}

bool is_1_operand_op(const int& op_code)
{
    bool is_1_operand = false;
    switch (op_code)
    {
        case op_sq:
            is_1_operand = true;
            break;
        case op_sqrt:
            is_1_operand = true;
            break;
        case op_exp_e:
            is_1_operand = true;
            break;
        case op_log_e:
            is_1_operand = true;
            break;
        case op_exp_10:
            is_1_operand = true;
            break;
        case op_log_10:
            is_1_operand = true;
            break;
        case op_inv:
            is_1_operand = true;
            break;
        case op_abs:
            is_1_operand = true;
            break;
        case op_sin:
            is_1_operand = true;
            break;
        case op_cos:
            is_1_operand = true;
            break;
        case op_tan:
            is_1_operand = true;
            break;
        case op_sin_inv:
            is_1_operand = true;
            break;
        case op_cos_inv:
            is_1_operand = true;
            break;
        case op_tan_inv:
            is_1_operand = true;
            break;
        case op_hyp_sin:
            is_1_operand = true;
            break;
        case op_hyp_cos:
            is_1_operand = true;
            break;
        case op_hyp_tan:
            is_1_operand = true;
            break;
        case op_hyp_sin_inv:
            is_1_operand = true;
            break;
        case op_hyp_cos_inv:
            is_1_operand = true;
            break;
        case op_hyp_tan_inv:
            is_1_operand = true;
            break;
        case op_rnd:
            is_1_operand = true;
            break;
        case op_int:
            is_1_operand = true;
            break;
        case op_fact:
            is_1_operand = true;
            break;
        case op_frac:
            is_1_operand = true;
            break;
        case op_swap_x:
            is_1_operand = true;
            break;

        default:
            break;
    }
    return is_1_operand;
}

bool is_0_operand_op(const int& op_code)
{
    bool is_0_operand = false;
    switch (op_code)
    {
        case op_random:
            is_0_operand = true;
            break;
        case op_pi:
            is_0_operand = true;
            break;
        case op_mem:
            is_0_operand = true;
            break;
        case op_2dec:
            is_0_operand = true;
            break;
        case op_2deg:
            is_0_operand = true;
            break;
        case op_2rad:
            is_0_operand = true;
            break;
        case op_2min:
            is_0_operand = true;
            break;
        case op_2pol:
            is_0_operand = true;
            break;
        case op_2rect:
            is_0_operand = true;
            break;
        case op_lstx:
            is_0_operand = true;
            break;
        case op_rcl:
            is_0_operand = true;
            break;
        case op_sto:
            is_0_operand = true;
            break;

        default:
            break;
    }
    return is_0_operand;
}

int digit_op_value(const int& op_code)
{
    static const int digit_key[] = {op_0, op_1, op_2, op_3, op_4, op_5, op_6, op_7, op_8, op_9};
    for (int i = 0; i < 10; i++)
    {
        if (op_code == digit_key[i])
            return i;
    }

    return -1;
}

bool is_digit_op(const int& op_code)
{
    bool is_digit = false;
    if (digit_op_value(op_code) != -1)
        is_digit = true;

    return is_digit;
}

bool is_trigono_op(const int& op_code)
{
    bool is_trigono = false;
    if (( op_code >= op_sin && op_code <= op_tan ) || 
        ( op_code >= op_sin_inv && op_code <= op_tan_inv ) ||
        ( op_code >= op_hyp_sin && op_code <= op_hyp_tan ) ||
        ( op_code >= op_hyp_sin_inv && op_code <= op_hyp_tan_inv ))
        is_trigono = true;

    return is_trigono;
}

void ledPrint(const int& value_size, const int& precision, const char* buffer,
    DFRobot_LedDisplayModule& ledPtr)
{
    static char digit[8][3] = {{0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0},
                               {0, 0, 0}};
    int digit_i = value_size;

    int len = value_size;
    if (precision > 0)
        len++;

    bool point = false;
    for (int i = len; i >= 0; i--)
    {
        if (buffer[i] == '.')
        {
            point = true;
        }

        else if (point)
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

    switch (value_size)
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

void setLedDisplayArea(const int& value_size,
    DFRobot_LedDisplayModule& ledPtr)
{
    switch (value_size)
    {
        case 1:
            if (is_left_aligned)
                ledPtr.setDisplayArea(1);

            else
                ledPtr.setDisplayArea(8);
            break;

        case 2:
            if (is_left_aligned)
                ledPtr.setDisplayArea(1, 2);
            else
                ledPtr.setDisplayArea(7, 8);
            break;

        case 3:
            if (is_left_aligned)
                ledPtr.setDisplayArea(1, 2, 3);
            else
                ledPtr.setDisplayArea(6, 7, 8);
            break;

        case 4:
            if (is_left_aligned)
                ledPtr.setDisplayArea(1, 2, 3, 4);
            else
                ledPtr.setDisplayArea(5, 6, 7, 8);
            break;

        case 5:
            if (is_left_aligned)
                ledPtr.setDisplayArea(1, 2, 3, 4, 5);
            else
                ledPtr.setDisplayArea(4, 5, 6, 7, 8);
            break;

        case 6:
            if (is_left_aligned)
                ledPtr.setDisplayArea(1, 2, 3, 4, 5, 6);
            else
                ledPtr.setDisplayArea(3, 4, 5, 6, 7, 8);
            break;

        case 7:
            if (is_left_aligned)
                ledPtr.setDisplayArea(1, 2, 3, 4, 5, 6, 7);
            else
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

void setDisplayArea(const int& value_size)
{
    if (value_size > 8)
    {
        if (is_left_aligned)
        {
            setLedDisplayArea(8, LEDLeft);
            setLedDisplayArea(value_size - 8, LEDRight);
            LEDRight.displayOn();
        }

        else
        {
            setLedDisplayArea(8, LEDRight);
            setLedDisplayArea(value_size - 8, LEDLeft);
            LEDLeft.displayOn();
        }
    }

    else if (is_left_aligned)
    {
        setLedDisplayArea(value_size, LEDLeft);
        LEDRight.displayOff();
    }

    else
    {
        setLedDisplayArea(value_size, LEDRight);
        LEDLeft.displayOff();
    }
}

void display(const double& value, const int& last_digit_i = 0)
{
    int value_size = log10(long(abs(value))) + precision + 1;
    
    if (last_digit_i > 0) {
        value_size = last_digit_i;
    }
    if (value == 0.0) { 
        value_size = 1 + precision;
    }
    if (value < 1.0) {
        value_size = 1 + precision;
    }
    if (value < 0) {
        value_size = value_size + 1;
    }

    Serial.println(" ");
    Serial.print(__func__);
    Serial.print(" : value = ");
    Serial.println(value);
    Serial.print(__func__);
    Serial.print(" : value_size = ");
    Serial.println(value_size);

    setDisplayArea(value_size);
    if (value_size > 8)
    {
        if (is_left_aligned) {
            dtostrf(value, value_size - precision, precision, str2);
            strncpy(str1, &str2[(8)],10);
        } else {
            double sh = powf(10,(8-precision));
            double d1 = trunc(value / sh);
            double d2 = abs(value - (d1 * sh));
            dtostrf(d1, value_size - 8, 0, str1);
            dtostrf(d2, 9, precision, str2);
        }
        for (int i = 0; i < 9; i++)
            {
            if (str2[i] == 0x0)
                break;

            if (str2[i] == ' ')
                str2[i] = '0';

            if (str2[i] == '-')
                str2[i] = '0';
            }

        if (is_left_aligned)
        {
            ledPrint(value_size - 8, 0, str1, LEDRight);
            ledPrint(8, precision, str2, LEDLeft);

            Serial.print(__func__);
            Serial.print(" : str1 = ");
            Serial.println(str1);
            Serial.print(__func__);
            Serial.print(" : str2 = ");
            Serial.println(str2);
        }
        else
        {
            ledPrint(value_size - 8, 0, str1, LEDLeft);
            ledPrint(8, precision, str2, LEDRight);

            Serial.print(__func__);
            Serial.print(" : str1 = ");
            Serial.println(str1);
            Serial.print(__func__);
            Serial.print(" : str2 = ");
            Serial.println(str2);
        }
    }

    else if (is_left_aligned)
    {
        dtostrf(value, value_size - precision, precision, str2);
        ledPrint(value_size, precision, str2, LEDLeft);

        Serial.print(__func__);
        Serial.print(" : str2 = ");
        Serial.println(str2);
        Serial.print(__func__);
        Serial.print(" : precision = ");
        Serial.println(precision);
    }

    else
    {
        dtostrf(value, value_size - precision, precision, str2);
        ledPrint(value_size, precision, str2, LEDRight);

        Serial.print(__func__);
        Serial.print(" : str2 = ");
        Serial.println(str2);
        Serial.print(__func__);
        Serial.print(" : precision = ");
        Serial.println(precision);
    }

    Serial.println(" ");
}

void clear_entered(int& decimal_incr, bool& entered, int& last_digit_i)
{
    Serial.println(__func__);
    decimal_incr = 0;
    in = 0;
    entered = false;
    last_digit_i = 0;
}

void stack_up()
{
    Serial.println(__func__);
    t = z;
    z = y;
    y = x;
}

void stack_drop()
{
    Serial.println(__func__);
    y = z;
    z = t;
}

void stack_roll_up()
{
    Serial.println(__func__);
    double temp = t;
    t = z;
    z = y;
    y = x;
    x = temp;
}

void stack_roll_down()
{
    Serial.println(__func__);
    double temp = x;
    x = y;
    y = z;
    z = t;
    t = temp;
}

void swap_xy(const bool& entered)
{
    Serial.println(__func__);
    double temp;
    if (entered)
    {
        temp = in;
        t = z;
        z = y;
        y = temp;
    }
    else
    {
        temp = x;
        x = y;
        y = temp;
    }
}

// operations with 2 operands
// **************************
void plus(const double& a, const double& b)
{
    Serial.println(__func__);
    x = a + b;
}

void minus(const double& a, const double& b)
{
    Serial.println(__func__);
    x = a - b;
}

void divide(const double& a, const double& b)
{
    Serial.println(__func__);
    x = a / b;
}

void mult(const double& a, const double& b)
{
    Serial.println(__func__);
    x = a * b;
}

void xpow(const double& a, const double& b)
{
    Serial.println(__func__);
    x = pow(a, b);
}

void percent(const double& a, const double& b)
{
    Serial.println(__func__);
    x = a * (b / 100);
}

void dpercent(const double& a, const double& b)
{
    Serial.println(__func__);
    x = ((b - a) / a) * 100;
}
void noop_2(const double& a, const double& b) 
{
    Serial.println(__func__);
    Serial.println("Operation not defined. Please fix the bug!");
}

// operations with 1 operand
// *************************
void square(const double& a)
{
    Serial.println(__func__);
    x = sq(a);
}

void square_root(const double& a)
{
    Serial.println(__func__);
    x = sqrt(a);
}

void log_e(const double& a)
{
    Serial.println(__func__);
    x = log(a);
}

void exp_e(const double& a)
{
    Serial.println(__func__);
    x = pow(e, a);
}

void log_10(const double& a)
{
    Serial.println(__func__);
    x = log10(a);
}

void exp_10(const double& a)
{
    Serial.println(__func__);
    x = pow(10.0, a);
}

void inverse(const double& a)
{
    Serial.println(__func__);
    x = 1 / a;
}

void sine(const double& a)
{
    Serial.println(__func__);
    x = sin(a);
}

void cosine(const double& a)
{
    Serial.println(__func__);
    x = cos(a);
}

void tangent(const double& a)
{
    Serial.println(__func__);
    x = tan(a);
}

void arcsine(const double& a)
{
    Serial.println(__func__);
    x = asin(a);
}

void arccosine(const double& a)
{
    Serial.println(__func__);
    x = acos(a);
}

void arctangent(const double& a)
{
    Serial.println(__func__);
    x = atan(a);
}

void hypersine(const double& a)
{
    Serial.println(__func__);
    x = sinh(a);
}

void hypercosine(const double& a)
{
    Serial.println(__func__);
    x = cosh(a);
}

void hypertangent(const double& a)
{
    Serial.println(__func__);
    x = tanh(a);
}

void hyperarcsine(const double& a)
{
    Serial.println(__func__);
    x = log(a + sqrt(sq(a) + 1));
}

void hyperarccosine(const double& a)
{
    Serial.println(__func__);
    x = log(a + sqrt(sq(a) - 1));
}

void hyperarctangent(const double& a)
{
    Serial.println(__func__);
    x = log((1 + a) / (1 - a)) / 2;
}
void noop_1(const double& a)
{
    Serial.println(__func__);
    Serial.println("Operation not defined. Please fix the bug!");
}

// Operations with 0 operand
// *************************
void pi_value()
{
    Serial.println(__func__);
    x = pi;
}
void noop_0()
{
    Serial.println(__func__);
    Serial.println("Operation not defined. Please fix the bug!");
}

void process_key(const int& key,
    bool& f_selected,
    bool& g_selected,
    bool& entered,
    bool& fix_selected,
    bool& hyp_selected,
    bool& hyp_inv_selected,
    bool& gto_selected,
    int* last_digit_key,
    int& last_digit_i,
    int& decimal_incr)
{
    // set op code based on pressed key 
    // and if g or f prefix selected or
    // if hyp or hyp_inv prefix selected

    Serial.println(" ");

    int op_code = key;
    if (f_selected) {
        op_code = op_code * -1;
        f_selected = false;
    } 
    if (g_selected) {
        op_code = op_code + 40;
        g_selected = false;
    }
    if (hyp_selected and is_trigono_op(op_code)) {
        op_code = op_code + 100;
        hyp_selected = false;
    }
    if (hyp_inv_selected and is_trigono_op(op_code)) {
        op_code = op_code + 100;
        hyp_inv_selected = false;
    }

    // set selected prefix
    switch (op_code) {
        case op_gto:
            gto_selected = true;
        case op_hyp:
            hyp_selected = true;
        case op_hyp_inv:
            hyp_inv_selected = true;
        case op_fix:
            fix_selected = true;
        
        // process op code
        default:

            // digit input ?
            if (is_digit_op(op_code))
            {
                Serial.print("digit entered = ");
                Serial.println(digit_op_value(op_code));
                
                // fix prefix selected 
                if (fix_selected)
                {
                    fix_selected = false;
                    precision = digit_op_value(op_code);
                    if (precision > 7)
                        precision = 7;

                    if (entered) {
                        display(in, last_digit_i);
                        entered = false;
                    }
                    else
                        display(x);
                } 
                else
                {
                    if (last_digit_i < 9)
                    {
                        last_digit_key[last_digit_i] = digit_op_value(op_code);
                        last_digit_i++;
                    }
                    else
                    {
                        for (last_digit_i = 0; last_digit_i < 9; last_digit_i++) {
                            last_digit_key[last_digit_i] = last_digit_key[last_digit_i + 1];
                        }
                        last_digit_key[last_digit_i] = digit_op_value(op_code);
                    }
                    if (__FLT_MAX__ - digit_op_value(op_code) < in * pow(10, decimal_incr))
                    {
                        in = __FLT_MAX__;
                    }
                    else if (decimal_incr >= 0)
                    {
                        in = in * pow(10, decimal_incr) + digit_op_value(op_code);
                        decimal_incr = 1;
                    }
                    else
                    {
                        in = in + digit_op_value(op_code) * pow(10, decimal_incr);
                        decimal_incr--;
                    }
                    entered = true;
                    display(in, last_digit_i);
                }
            }

            // enter key pressed
            else if (op_code == op_enter)
            {
                stack_up();
                if (entered) {
                    x = in;                    
                }
                clear_entered(decimal_incr, entered, last_digit_i);
                display(x);
            }

            // 2 operands operations with stack drop
            else if (is_2_operands_op(op_code))
            {
                void (*oper)(const double&, const double&) = noop_2;
                switch (key)
                {
                    case op_plus:
                        oper = plus;
                        break;
                    case op_minus:
                        oper = minus;
                        break;
                    case op_div:
                        oper = divide;
                        break;
                    case op_mult:
                        oper = mult;
                        break;
                    case op_xpow:
                        oper = xpow;
                        break;
                    case op_percent:
                        oper = percent;
                        break;
                    case op_dpercent:
                        oper = dpercent;
                        break;
                    default:
                        oper = noop_2;
                        break;
                }
                if (entered)
                {
                    oper(x, in);
                    clear_entered(decimal_incr, entered, last_digit_i);
                    stack_drop();
                }
                else
                {
                    oper(y, x);
                    stack_drop();
                }
                display(x, last_digit_i);
            }

            // 1 operand operations (without stack drop)
            else if (is_1_operand_op(op_code))
            {
                void (*oper)(const double&);
                switch (op_code)
                {
                    case op_hyp_sin_inv:
                        oper = hyperarcsine;
                        break;
                    case op_hyp_cos_inv:
                        oper = hyperarccosine;
                        break;
                    case op_hyp_tan_inv:
                        oper = hyperarctangent;
                        break;
                    case op_hyp_sin:
                        oper = hypersine;
                        break;
                    case op_hyp_cos:
                        oper = hypercosine;
                        break;
                    case op_hyp_tan:
                        oper = hypertangent;
                        break;
                    case op_sin_inv:
                        oper = arcsine;
                        break;
                    case op_cos_inv:
                        oper = arccosine;
                        break;
                    case op_tan_inv:
                        oper = arctangent;
                        break;
                    case op_sin:
                        oper = sine;
                        break;
                    case op_cos:
                        oper = cosine;
                        break;
                    case op_tan:
                        oper = tangent;
                        break;
                    case op_sq:
                        oper = square;
                        break;
                    case op_exp_e:
                        oper = exp_e;
                        break;
                    case op_exp_10:
                        oper = exp_10;
                        break;
                    case op_sqrt:
                        oper = square_root;
                        break;
                    case op_inv:
                        oper = inverse;
                        break;
                    default:
                        oper = noop_1;
                        break;
                }
                if (entered)
                {
                    oper(in);
                    display(x, 0);
                    clear_entered(decimal_incr, entered, last_digit_i);
                } else
                {
                    oper(x);
                    display(x);
                }
            }

            // 0 operand key (constants)
            else if (is_0_operand_op(op_code))
            {
                void (*oper)();
                switch (op_code)
                {
                    // case op_random:
                    //     is_0_operand = true;
                    //     break;
                    case op_pi:
                        oper = pi_value;
                        break;
                    // case op_mem:
                    //     is_0_operand = true;
                    //     break;
                    // case op_2dec:
                    //     is_0_operand = true;
                    //     break;
                    // case op_2deg:
                    //     is_0_operand = true;
                    //     break;
                    // case op_2rad:
                    //     is_0_operand = true;
                    //     break;
                    // case op_2min:
                    //     is_0_operand = true;
                    //     break;
                    // case op_2pol:
                    //     is_0_operand = true;
                    //     break;
                    // case op_2rect:
                    //     is_0_operand = true;
                    //     break;
                    // case op_lstx:
                    //     is_0_operand = true;
                    //     break;
                    // case op_rcl:
                    //     is_0_operand = true;
                    //     break;
                    // case op_sto:
                    //     is_0_operand = true;
                    //     break;
                    default:
                        oper = noop_0;
                        break;
                }

                if (entered)
                {
                    stack_up();
                    x = in;
                    clear_entered(decimal_incr, entered, last_digit_i);
                }

                stack_up();
                oper();
                display(x, last_digit_i);
            }

            // +/- key pressed
            // ---------------
            else if (key == op_chs)
            {
                // abs(x)
                if (g_selected)
                {
                    g_selected = false;
                    if (entered)
                    {
                        in = abs(in);
                        display(in, last_digit_i);
                    }

                    else
                    {
                        x = abs(x);
                        display(x);
                    }

                }

                // +/- (CHS)
                else if (entered)
                {
                    if (in != 0)
                    {
                        in = in * -1;
                        display(in, last_digit_i);
                    }
                }

                else if (x != 0)
                {
                    x = x * -1;
                    display(x);
                }
            }

            // down key pressed
            // ----------------
            else if (key == op_down)
            {
                // stack roll up
                if (g_selected)
                {
                    g_selected = false;
                    if (entered)
                        x = in;

                    stack_roll_up();
                    clear_entered(decimal_incr, entered, last_digit_i);
                    display(x, last_digit_i);

                    // stack roll down
                }

                else
                {
                    if (entered)
                        x = in;

                    stack_roll_down();
                    clear_entered(decimal_incr, entered, last_digit_i);
                    display(x, last_digit_i);
                }
            }

            //    swap key pressed
            //    ----------------
            else if (key == op_swap_y_x)
            {
                // clear x
                if (g_selected)
                {
                    g_selected = false;
                    if (entered)
                        clear_entered(decimal_incr, entered, last_digit_i);

                    x = 0;
                    display(x, last_digit_i);
                }

                // swap xy
                else
                {
                    swap_xy(entered);
                    if (entered)
                        clear_entered(decimal_incr, entered, last_digit_i);

                    display(x, last_digit_i);
                }
            }
        }
}

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < key_count; i++)
        pinMode(key[i], INPUT);

    while (LEDRight.begin(LEDRight.e8Bit) != 0)
    {
        Serial.println("LED Right: Failed to initialize the chip , please confirm "
            "the chip connection!");
        delay(1000);
    }

    if (is_left_aligned)
    {
        LEDLeft.setDisplayArea();
        LEDLeft.displayOff();
    }

    else
    {
        LEDRight.setDisplayArea();
        LEDRight.displayOff();
    }

    while (LEDLeft.begin(LEDLeft.e8Bit) != 0)
    {
        Serial.println("LED Left: Failed to initialize the chip , please confirm "
            "the chip connection!");
        delay(1000);
    }

    if (is_left_aligned)
    {
        LEDRight.setDisplayArea();
        LEDRight.displayOff();
        LEDLeft.displayOn();
    }

    else
    {
        LEDLeft.setDisplayArea();
        LEDLeft.displayOff();
        LEDRight.displayOn();
    }

    delay(100);

    Serial.println(" ");
    Serial.println("***** STARTING MAX7141 HP15 DIY *****");
    Serial.println(" ");
    Serial.print("__FLT_MAX__         : ");
    dtostre(__FLT_MAX__, str, 9, 0);
    Serial.println(str);
    Serial.print("__FLT_MIN__         : ");
    dtostre(__FLT_MIN__, str, 9, 0);
    Serial.println(str);
    Serial.print("__FLT_MAX_10_EXP__  : ");
    Serial.println(__FLT_MAX_10_EXP__);
    Serial.print("__FLT_MIN_10_EXP__  : ");
    Serial.println(__FLT_MIN_10_EXP__);
    Serial.print("__FLT_DIG__         : ");
    Serial.println(__FLT_DIG__);
    Serial.print("__FLT_DECIMAL_DIG__ : ");
    Serial.println(__FLT_DECIMAL_DIG__);
    Serial.print("__FLT_MANT_DIG__    : ");
    Serial.println(__FLT_MANT_DIG__);
    Serial.println();

    display(x);
}

void loop()
{
// last entered digits 10 power increment
    static int last_digit_key[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    static int last_digit_i = 0;
    static int decimal_incr = 0;

    // pressed key flags
    static bool entered = false;
    static bool f_selected = false;
    static bool g_selected = false;
    static bool fix_selected = false;
    static bool hyp_selected = false;
    static bool hyp_inv_selected = false;
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
            pressed_key = kcode[i];
            delay(100);

            Serial.print("key = ");
            Serial.println(pressed_key);
            break;
        }
    }

    if (pressed_key == op_on)
    {
        if (is_left_aligned)
        {
            is_left_aligned = false;
            Serial.print("is_left_aligned = ");
            Serial.println(is_left_aligned);
            setup();
        }
        else
        {
            is_left_aligned = true;
            Serial.print("is_left_aligned = ");
            Serial.println(is_left_aligned);
            setup();
        }
    }

    // alternate (f) key pressed
    // -------------------------
    else if (pressed_key == op_f)
    {
        f_selected = true;
        g_selected = false;
        Serial.println("+");
    }

    // alternate (g) ley pressed
    // -------------------------
    else if (pressed_key == op_g)
    {
        g_selected = true;
        f_selected = false;
        Serial.println("+");
    }

    // del key pressed
    // ---------------
    else if (pressed_key == op_del)
    {
        if (entered && last_digit_i > 0)
        {
            in = round((in - last_digit_key[last_digit_i]) / decimal_incr);
            last_digit_i--;
            display(in, last_digit_i);
        }

        else
        {
            clear_entered(decimal_incr, entered, last_digit_i);
            x = 0;
            display(x);
        }

        Serial.print("t = ");
        Serial.println(t);
        Serial.print("z = ");
        Serial.println(z);
        Serial.print("y = ");
        Serial.println(y);
        Serial.print("x = ");
        Serial.println(x);
        if (entered)
        {
            Serial.print("in = ");
            Serial.println(in);
        }
        Serial.println("--------------------------------------------");
    }

    // decimal point key pressed
    // -------------------------
    else if (pressed_key == op_dp)
    {
        Serial.println("+");

        if (entered && last_digit_i > 0)
        {
            decimal_incr = -1;
        }
        else
        {
            stack_up();
            clear_entered(decimal_incr, entered, last_digit_i);
            decimal_incr = -1;
            display(x, last_digit_i);
            entered = true;
        }

        // other keys, which can be used in a pgm
        // --------------------------------------
    }
    else if (pressed_key != 0)
    {
        process_key(pressed_key, f_selected, g_selected, entered, fix_selected,
            hyp_selected, hyp_inv_selected, gto_selected, last_digit_key,
            last_digit_i, decimal_incr);

        Serial.print("t = ");
        Serial.println(t);
        Serial.print("z = ");
        Serial.println(z);
        Serial.print("y = ");
        Serial.println(y);
        Serial.print("x = ");
        Serial.println(x);
        if (entered)
        {
            Serial.print("in = ");
            Serial.println(in);
        }
        Serial.println("--------------------------------------------");
    }

    // wait 1/10 seconds for next key press
    delay(150);
}