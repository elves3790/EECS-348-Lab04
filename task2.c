#include <stdio.h>

void convert_temperature(char old_scale,char new_scale,float  temp); {

if (old_scale == new_scale){
	printf("Converted Temperature: %.2f\n", temp);
 }else if (old_scale == "C" && new_scale == "F"){
	temp = (temp *1.8) +32;
 } else if (old_scale == "F" && new_scale == "C"){
	temp = (temp -32) * (5/9);
 } else if (old_scale == "C" && new_scale == "K") {
	temp =  temp + 273.15;
 } else if (old_scale == "K" && new_scale == "C") {
	temp = temp - 273.15;
 } else if (old_scale == "F" && new_scale == "K") {
	temp =((temp - 32)/1.8)+273.15;
 } else if (old_scale == "K" && new_scale == "F") {
	temp  = (( temp - 273.15)*1.8) + 32;
 }
 printf("Converted Temperature: %.2f\n", temp);
 temp_category(new_scale, temp);
}

void temp_category(char scale, float temp) {
    float celsius = temp;

    // Convert to Celsius if the temperature is currently in Fahrenheit or Kelvin
    if (scale == 'F' || scale == 'f') {
        celsius = (temp - 32.0f) * (5.0f / 9.0f);
    } else if (scale == 'K' || scale == 'k') {
        celsius = temp - 273.15f;
    }

    // Categorize based on Celsius
    if (celsius < 0.0f) {
	printf("Temperature Category: Freezing\n ")
        printf("Dress warmly and watch for ice.\n");
    } else if (celsius <= 10.0f) {
	printf("Temperature Category: Cold\n ")
        printf("Wear a warm coat.\n");
    } else if (celsius <= 25.0f) {
	printf("Temperature Category: Comfortable \n");
        printf("Enjoy the pleasant weather.\n");
    } else if (celsius <= 35.0f) {
	printf("Temperature Category: Hot\n"
        printf("Stay hydrated.\n");
    } else {
	printf("Temperature Category: Extreme heat\n"
        printf("Stay indoors and keep cool.\n");
    }
}
int main() {
float temp;
char scale;
char conversion;

printf("Enter the temperature value:");
scanf(" %f",&temp);

printf("Enter the original scale:");
scanf(" %c",&scale);

printf("Enter the scale to (C,F, or K)");
scanf(" %c", &conversion);

convert_temperature(scale,conversion,temp);



}
