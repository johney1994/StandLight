#include <iostream>
#include "Button.h"
#include "Led.h"
#include <wiringPi.h>
#include "Listener.h"
#include "Controller.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    
    Button button1(27);
    Led led1(25);
    View view(&led1);
    Controller control(&view);
    Listener listener(&button1, &control);
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        delay(50);
    }

    return 0;
}