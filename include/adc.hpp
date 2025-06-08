#ifndef ADC_HPP
#define ADC_HPP

class ADC {
public:
    void init();
    int readTemp();
};
extern ADC adc;
#endif