/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : clac.c
 Data      : Oct 4, 2023
 Time      : 10:45:27 PM
 ===================================================
 */
#include "keypad.h"
#include "lcd.h"
#include <util/delay.h>
#define tenReverance 10
int main(void) {
	LCD_init();
	sint64 num[2] = { 0, 0 };
	uint8 counter = 0, operation, temp;
	LCD_displayStringRowColumn(0, 2, "Simple");
	LCD_displayStringRowColumn(1, 5, "Calculator");
	_delay_ms(500);
	LCD_clearScreen();
	while (1) {
		temp = KEYPAD_getPressedKey();
		if (temp == 'C') {
			LCD_clearScreen();
			counter = 0;
			num[0] = 0;
			num[1] = 0;
		}
		if ((temp <= 9) && (temp >= 0)) {
			LCD_intgerToString(temp);
			_delay_ms(300);
			num[counter] = (tenReverance * num[counter]) + temp;
		} else {
			if (temp != '=' && temp != 'C') {
				LCD_displayCharacter(temp);
				_delay_ms(300);
				operation = temp;
				counter++;
			} else if (temp == '=') {
				LCD_displayCharacter(temp);
				_delay_ms(300);
				counter = 0;
			}
		}
		if (temp == '=') {
			LCD_moveCursor(1, 0);
			switch (operation) {
			case '+':
				LCD_intgerToString((num[0] + num[1]));
				_delay_ms(300);
				break;
			case '-':
				LCD_intgerToString((num[0] - num[1]));
				_delay_ms(300);
				break;
			case '*':
				LCD_floatToString((num[0] * num[1]));
				_delay_ms(300);
				break;
			case '%':
				LCD_floatToString((((float) num[0]) / num[1]));
				_delay_ms(300);
				break;
			default:
				break;
			}
		}
	}

}
