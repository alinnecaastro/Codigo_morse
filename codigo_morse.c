#include <stdio.h>
#include "pico/stdlib.h"


//Função para enviar o sinal de morse (.) (-).
void send_morse_red(int duration){
    gpio_put(13,1);
    sleep_ms(duration);
    gpio_put(13,0);
}

void send_morse_green(int duration){
    gpio_put(11,1);
    sleep_ms(duration);
    gpio_put(11,0);
}

void send_morse_blue(int duration){
    gpio_put(12,1);
    sleep_ms(duration);
    gpio_put(12,0);
}
//função para enviar o SOS em codigo morse
void send_sinal(){
    
    for(int i;i<3;i++){
        send_morse_red(200);
        sleep_ms(125);
    }

    sleep_ms(250);

    for (int i = 0; i < 3; i++) {
        send_morse_green(200);
        sleep_ms(125);
    }

    for(int i=0;i<3;i++){
        send_morse_blue(200);
        sleep_ms(125);
    }

}


int main()
{
    gpio_init(13);
    gpio_set_dir(13, GPIO_OUT);
    gpio_init(11);      
    gpio_set_dir(11, GPIO_OUT); 
    gpio_init(12);
    gpio_set_dir(12, GPIO_OUT);
    
    stdio_init_all();
//Loop para enviar o sinal SOS
    while (true) {
        send_sinal();
        sleep_ms(3000);
    }
}
