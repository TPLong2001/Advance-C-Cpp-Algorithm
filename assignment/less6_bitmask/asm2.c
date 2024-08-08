#include <stdio.h>
#include <stdint.h>

//2 bit
#define COLOR_BIT_OFSET 3
#define COLOR_RED 0	
#define COLOR_BLUE 1
#define COLOR_BLACK 2
#define COLOR_WHITE 3

//2 bit
#define POWER_BIT_OFSET 5
#define POWER_100HP 0
#define POWER_150HP 1
#define POWER_200HP 2

//1 bit
#define ENGINE_BIT_OFSET 7
#define ENGINE_1_5L 0
#define ENGINE_2_0L 1

typedef uint8_t CarColor;
typedef uint8_t CarPower;
typedef uint8_t CarEngine;

// 0 00 00 000
//      00

// Bitmask
#define SUNROOF_MASK            1 << 0              // 0001
#define PREMIUM_AUDIO_MASK      1 << 1              // 0010
#define SPORTS_PACKAGE_MASK     1 << 2              // 0100
// Thêm các bit masks khác tùy thuộc vào tùy chọn
#define COLOR_RED_MASK          (COLOR_RED) << COLOR_BIT_OFSET    // 0 00 00 000
#define COLOR_BLUE_MASK         (COLOR_BLUE) << COLOR_BIT_OFSET   // 0 00 01 000
#define COLOR_BLACK_MASK        (COLOR_BLACK) << COLOR_BIT_OFSET  // 0 00 10 000
#define COLOR_WHITE_MASK        (COLOR_WHITE) << COLOR_BIT_OFSET  // 0 00 11 000

#define POWER_100HP_MASK        (POWER_100HP) << POWER_BIT_OFSET  // 0 00 00 000
#define POWER_150HP_MASK        (POWER_150HP) << POWER_BIT_OFSET  // 0 01 00 000
#define POWER_200HP_MASK        (POWER_200HP) << POWER_BIT_OFSET  // 0 10 00 000

#define ENGINE_1_5L_MASK        (ENGINE_1_5L) << ENGINE_BIT_OFSET // 0 00 00 000
#define ENGINE_2_0L_MASK        (ENGINE_2_0L) << ENGINE_BIT_OFSET // 1 00 00 000

typedef struct {
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung
    CarColor color : 2;
    CarPower power : 2;
    CarEngine engine : 1;
    
} CarOptions;



void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options) {
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}

void setOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions |= optionMask;
}

void unsetOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions &= ~optionMask;
}


void displayCarOptions(const CarOptions car) {
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]);
    printf("Power: %s\n", powers[car.power]);
    printf("Engine: %s\n", engines[car.engine]);
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}

int main() {
    CarOptions myCar;
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0); 
	

    setOption(&myCar, SUNROOF_MASK);
    setOption(&myCar, PREMIUM_AUDIO_MASK);
    
    displayCarOptions(myCar);

    unsetOption(&myCar, PREMIUM_AUDIO_MASK); 
    displayCarOptions(myCar);

    printf("size of my car: %d\n", sizeof(CarOptions));

    return 0;
}



