#include <IRremote.h>
#include <avr/io.h>

// Made by : Akarsh, Rudraksha, Steven, Amogha
// akarshs.malvekar@gmail.com

// IR pin
const byte IRpin = 0;
volatile int state;
int ir_delay = 100;

void setup() {
  IrSender.begin(IRpin);
  DDRB &= ~(1 << DDB1);  //set PB1 as input
  PORTB |= (1 << PB1);   //activate pull-up resistor for PB1
  DDRB &= ~(1 << DDB2);  //set PB2 as input
  PORTB |= (1 << PB2);   //activate pull-up resistor for PB2
  DDRB &= ~(1 << DDB3);  //set PB3 as input
  PORTB |= (1 << PB3);   //activate pull-up resistor for PB3
  DDRB &= ~(1 << DDB4);  //set PB4 as input
  PORTB |= (1 << PB4);   //activate pull-up resistor for PB4
  state = 0;
}

void loop() {
  bool power_state = PINB & (1 << PB1);
  bool select_state = PINB & (1 << PB2);
  bool menu_state = PINB & (1 << PB3);
  bool up_state = PINB & (1 << PB4);


  if (!power_state) {
    power();

  }

  // select_state
  else if (!select_state) {

    select();
    check_state();

  }

  // UP-RIGHT
  else if (!up_state) {

    if (state == 2) {
      right();
    }

    else {
      up();
    }
  }

  // menu_state - DOWN - LEFT
  else if (!menu_state) {

    if (state == 0) {
      menu();
    }

    else if (state == 1) {
      down();
    }

    else if (state == 2) {
      left();
    }
  }
}


//if you want to assign different IR code , change the below function
void power()
{
  //PB1 or pin 6 on IC
  IrSender.sendNEC( 0x8C73817E, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x8C73817E, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC40BF, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC40BF, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC1AA09F6, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB3817E, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB3817E, 32);
  delay(ir_delay);

}

void menu()
{
  //PB4 or pin 3 on IC
  IrSender.sendNEC( 0x8C73E11E, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x8C73E11E, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xCF00F, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC1AA59A6, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB311EE, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB311EE, 32);
  delay(ir_delay);

}

void select()
{
  //PB2 or pin 7 on IC
  delay(500);
  if ( state == 0) {
    IrSender.sendNEC( 0x8C73A35C, 32);
    delay(ir_delay);
    IrSender.sendNEC( 0x8C73A35C, 32);
    delay(ir_delay);
    IrSender.sendNEC( 0xCA857, 32);
    delay(ir_delay);
    IrSender.sendNEC( 0xC1AAA15E, 32);
    delay(ir_delay);
    IrSender.sendNEC( 0x4CB3A35C, 32);
    delay(ir_delay);
    IrSender.sendNEC( 0x4CB3A35C, 32);
    delay(ir_delay);
  }

}
void up()
{
  //PB3 or pin 2 on IC
  IrSender.sendNEC( 0x8C73837C, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x8C73837C, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xCD02F, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC1AA0DF2, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB3A15E, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB3A15E, 32);
  delay(ir_delay);


}

void down()
{
  //PB4 or pin 3 on IC
  IrSender.sendNEC(0x8C7343BC, 32);
  delay(ir_delay);
  IrSender.sendNEC(0x8C7343BC, 32);
  delay(ir_delay);
  IrSender.sendNEC(0xC30CF, 32);
  delay(ir_delay);
  IrSender.sendNEC(0xC1AA4DB2, 32);
  delay(ir_delay);
  IrSender.sendNEC(0x4CB321DE, 32);
  delay(ir_delay);
  IrSender.sendNEC(0x4CB321DE, 32);
  delay(ir_delay);
}
void right()
{
  //PB3 or pin 2 on IC
  IrSender.sendNEC( 0x8C7323DC, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x8C7323DC, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC708F, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC1AA8D72, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB331CE, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB331CE, 32);
  delay(ir_delay);


}

void left()
{
  //PB4 or pin 3 on IC
  IrSender.sendNEC( 0x8C73C33C, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x8C73C33C, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xCB04F, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0xC1AACD32, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB3F10E, 32);
  delay(ir_delay);
  IrSender.sendNEC( 0x4CB3F10E, 32);
  delay(ir_delay);


}

void check_state( ) {
  state = state + 1;
  if (state == 3) {
    state = 0;
  }
}
