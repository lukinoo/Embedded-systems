#include "stdio.h";
void rgb_led_control();

int main()
{

    rgb_led_control();

    return 0;
}

void rgb_led_control()
{
    // Activates Ports A and B
    RCC->AHBENR |= (1 << 17);
    RCC->AHBENR |= (1 << 19);

    // Input Pins
    // PA11
    GPIOA->MODER &= ~(3 << 22);
    GPIOA->OTYPER &= ~(1 << 11);
    GPIOA->OSPEEDR |= (1 << 22);
    GPIOA->PUPDR |= (2 << 22);

    // PA10
    GPIOA->MODER &= ~(3 << 20);
    GPIOA->OTYPER &= ~(1 << 10);
    GPIOA->OSPEEDR |= (1 << 20);
    GPIOA->PUPDR |= (2 << 20);

    // PA9
    GPIOA->MODER &= ~(3 << 18);
    GPIOA->OTYPER &= ~(1 << 9);
    GPIOA->OSPEEDR |= (1 << 18);
    GPIOA->PUPDR |= (2 << 18);

    // PA8
    GPIOA->MODER &= ~(3 << 16);
    GPIOA->OTYPER &= ~(1 << 8);
    GPIOA->OSPEEDR |= (1 << 16);
    GPIOA->PUPDR |= (2 << 16);

    // PC9
    GPIOC->MODER &= ~(3 << 18);
    GPIOC->OTYPER &= ~(1 << 9);
    GPIOC->OSPEEDR |= (1 << 18);
    GPIOC->PUPDR |= (2 << 18);

    // PC8
    GPIOC->MODER &= ~(3 << 16);
    GPIOC->OTYPER &= ~(1 << 8);
    GPIOC->OSPEEDR |= (1 << 16);
    GPIOC->PUPDR |= (2 << 16);

    // PC7
    GPIOC->MODER &= ~(3 << 14);
    GPIOC->OTYPER &= ~(1 << 7);
    GPIOC->OSPEEDR |= (1 << 14);
    GPIOC->PUPDR |= (2 << 14);

    // PC6
    GPIOC->MODER &= ~(3 << 12);
    GPIOC->OTYPER &= ~(1 << 6);
    GPIOC->OSPEEDR |= (1 << 12);
    GPIOC->PUPDR |= (2 << 12);

    // Output pins
    // PC0
    GPIOC->MODER |= (1 << 0);
    GPIOC->OTYPER &= ~(1 << 0);
    GPIOC->OSPEEDR |= (1 << 0);
    GPIOC->PUPDR &= ~(3 << 0);

    // PC1
    GPIOC->MODER |= (1 << 2);
    GPIOC->OTYPER &= ~(1 << 1);
    GPIOC->OSPEEDR |= (1 << 2);
    GPIOC->PUPDR &= ~(3 << 2);

    // PC2
    GPIOC->MODER |= (1 << 4);
    GPIOC->OTYPER &= ~(1 << 2);
    GPIOC->OSPEEDR |= (1 << 4);
    GPIOC->PUPDR &= ~(3 << 4);

    while (1)
    {

        int color = 0;

        // binary to decimal conversion

        if (GPIOC->IDR & (1 << 6))
        {
            color |= 1;
        }
        if (GPIOC->IDR & (1 << 7))
        {
            color |= 2;
        }
        if (GPIOC->IDR & (1 << 8))
        {
            color |= 4;
        }
        if (GPIOC->IDR & (1 << 9))
        {
            color |= 8;
        }
        if (GPIOA->IDR & (1 << 8))
        {
            color |= 16;
        }
        if (GPIOA->IDR & (1 << 9))
        {
            color |= 32;
        }
        if (GPIOA->IDR & (1 << 10))
        {
            color |= 64;
        }
        if (GPIOA->IDR & (1 << 11))
        { // SW8
            color |= 128;
        }

        if (color == 0 || color == 255)
        { // white
            GPIOC->ODR &= ~(1 << 0);
            GPIOC->ODR &= ~(1 << 1);
            GPIOC->ODR &= ~(1 << 2);
        }
        else if (color >= 1 && color <= 42)
        { // red
            GPIOC->ODR &= ~(1 << 0);
            GPIOC->ODR |= (1 << 1);
            GPIOC->ODR |= (1 << 2);
        }
        else if (color >= 128 && color <= 169)
        { // red & blue
            GPIOC->ODR &= ~(1 << 0);
            GPIOC->ODR &= ~(1 << 1);
            GPIOC->ODR |= (1 << 2);
        }
        else if (color >= 213 && color <= 254)
        { // blue & green
            GPIOC->ODR |= (1 << 0);
            GPIOC->ODR &= ~(1 << 1);
            GPIOC->ODR &= ~(1 << 2);
        }
        else if (color >= 43 && color <= 84)
        { // red & green
            GPIOC->ODR &= ~(1 << 0);
            GPIOC->ODR |= (1 << 1);
            GPIOC->ODR &= ~(1 << 2);
        }
        else if (color >= 170 && color <= 212)
        { // blue
            GPIOC->ODR |= (1 << 0);
            GPIOC->ODR &= ~(1 << 1);
            GPIOC->ODR |= (1 << 2);
        }
        else if (color >= 85 && color <= 127)
        {                            // green
            GPIOC->ODR |= (1 << 0);  // Red
            GPIOC->ODR |= (1 << 1);  // Blue
            GPIOC->ODR &= ~(1 << 2); // Green
        }
    }
}
