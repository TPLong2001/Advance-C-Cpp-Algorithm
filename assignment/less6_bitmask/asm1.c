#include <stdio.h>
#include <stdint.h>


#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;       // set bit: | với bitmask ở vị trí bit n (bit tại vị trí n = 1 còn lại = 0) theo feature để set bit đó lên 1.
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;      // clear bit: & với đảo của bitmask ở vị trí bit n (bit tại vị trí n = 0 còn lại = 1 do đã đảo) theo feature để clear bit đó về 0.
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {    // read bit: & với bitmask ở vị trí bit n (bit tại vị trí n = 1 còn lại = 0) theo feature để lấy bit tại vị trí n đó.
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("feature selected: %d\n", (features >> i) & 1);
    }
    

    // Thêm các điều kiện kiểm tra cho các tính năng khác
}



int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);     // feature = 0b00000111 => options = 0b00000111

    disableFeature(&options, TSHIRT);                   // feature = 0b00000010 => options = 0b00000101

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}
