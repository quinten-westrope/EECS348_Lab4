#include <stdio.h>

float celsius_to_fahrenheit (float celsius) {
    float f;

    // converting from celsius to fahrenheit
    f = (9.0 / 5.0) * celsius + 32;

    printf("Converted temperature: %.2f\n", f);

    return 0;
}


float celsius_to_kelvin (float celsius) {
    float k;

    // converting from celsius to kelvin
    k = celsius + 273.15;
    
    printf("Converted temperature: %.2fK\n", k);
       
    return 0;
}


float fahrenheit_to_celsius (float fahrenheit) {
    float c;
    
    // converting from fahrenheit to celsius
    c = (5.0 / 9.0) * (fahrenheit - 32);

    printf("Converted temperature: %.2f°C\n", c);

    return 0;
}


float fahrenheit_to_kelvin (float fahrenheit) {
    float k;

    // converting from fahrenheit to kelvin
    k = (((fahrenheit - 32) * 5) / 9.0) + 273.15;
    
    printf("Converted temperature: %.2fK\n", k);

    return 0;
}

float kelvin_to_celsius (float kelvin) {
    float c;

    // converting from kelvin to celsius
    c = kelvin - 273.15;

    printf("Converted temperature: %.2f°C\n", c);

    return 0;
}


float kelvin_to_fahrenheit (float kelvin) {
    float f;

    // converting from kelvin to fahrenheit
    f = (((kelvin - 273.15) * 9) / 5.0) + 32;

    printf("Converted temperature: %.2f\n", f);

    return 0;
}



void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay Inside\n");
    }
    else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a Coat\n");
    }
    else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Wear a Jacket\n");
    }
    else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Hydrate Well\n");
    }
    else if (celsius >= 35) {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay inside with the AC\n");
    }
}


void categorize_temperature2(float fahrenheit) {
    if (fahrenheit < 32) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay Inside\n");
    }
    else if (fahrenheit >= 32 && fahrenheit < 50) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a Coat\n");
    }
    else if (fahrenheit >= 50 && fahrenheit < 77) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Wear a Jacket\n");
    }
    else if (fahrenheit >= 77 && fahrenheit < 95) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Hydrate Well\n");
    }
    else if (fahrenheit >= 95) {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay inside with the AC\n");
    }
}


void categorize_temperature3(float kelvin) {
    if (kelvin < 273.15) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay Inside\n");
    }
    else if (kelvin >= 273.15 && kelvin < 283.15) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a Coat\n");
    }
    else if (kelvin >= 283.15 && kelvin < 298.15) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Wear a Jacket\n");
    }
    else if (kelvin >= 298.15 && kelvin < 308.15) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Hydrate Well\n");
    }
    else if (kelvin >= 308.15) {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay inside with the AC\n");
    }
}





int main() {

    // loop to break out of once program runs succesfully, or to re run if user inputs invalid input at any point
    while(1) {
        float temp = 0;
        int scale = 0;
        int convert = 0;

        // gathering inputs from user

        printf("Enter the temperature: \n");
        if (scanf("%f", &temp) != 1) {
            printf("Please enter a valid temperature value\n");
            // clear the invalid input
            while (getchar() != '\n');
            continue;
        }
        
        // making sure inputted temperature is in a realistic range
        if (temp < -200 || temp > 400) {
            printf("Please enter a realistic temperature\n");
            continue;
        }


        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: \n");
        if (scanf("%d", &scale) != 1 || scale < 1 || scale > 3) {
            printf("Please enter a valid scale option either 1, 2, or 3\n");
            // clear the invalid input
            while (getchar() != '\n');
            continue;
        }

        
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: \n");
        if (scanf("%d", &convert) != 1 || convert < 1 || convert > 3) {
            printf("Please enter a valid conversion option either 1, 2, or 3\n");
            // clear invalid input
            while (getchar() != '\n');
            continue;
        }

       
        if (scale == 1) {   // if user picks celsius as their scale
            if (convert == 1) {
                printf("Can't convert from Celsius to Celsius, please enter valid input\n");
                continue;
            }
            else if (convert == 2) {
                celsius_to_fahrenheit(temp);
                categorize_temperature(temp);
                break;
            }
            else if (convert == 3) {
                celsius_to_kelvin(temp);
                categorize_temperature(temp);
                break;
            }
        }
        else if (scale == 2) {  // if user picks fahrenheit as their scale
            if (convert == 1) {
                fahrenheit_to_celsius(temp);
                categorize_temperature2(temp);
                break;
            }
            else if (convert == 2) {
                printf("Can't convert from Fahrenheit to Fahrenheit, please enter valid input\n");
                continue;
            }
            else if (convert == 3) {    
                fahrenheit_to_kelvin(temp);
                categorize_temperature2(temp);
                break;
            }
        }
        else if (scale == 3) {  // if user picks kelvin as their scale
            // making sure Kelvin value is not negative
            if (temp < 0) {
                printf("Can't have negative Kelvin temperature, please enter valid input\n");
                continue;
            }


            if (convert == 1) {
                kelvin_to_celsius(temp);
                categorize_temperature3(temp);
                break;
            }
            else if (convert == 2) {
                kelvin_to_fahrenheit(temp);
                categorize_temperature3(temp);
                break;
            }
            else if (convert == 3) {
                printf("Can't convert from Kelvin to Kelvin, please enter valid input\n");
                continue;
            }
        }
        break;
    }

        return 0;
}