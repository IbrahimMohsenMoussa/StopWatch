################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/external_interrupts.c \
../src/gpio.c \
../src/multi_7_segment.c \
../src/pushbutton.c \
../src/stopwatch.c \
../src/timer_0.c \
../src/timer_1.c 

OBJS += \
./src/external_interrupts.o \
./src/gpio.o \
./src/multi_7_segment.o \
./src/pushbutton.o \
./src/stopwatch.o \
./src/timer_0.o \
./src/timer_1.o 

C_DEPS += \
./src/external_interrupts.d \
./src/gpio.d \
./src/multi_7_segment.d \
./src/pushbutton.d \
./src/stopwatch.d \
./src/timer_0.d \
./src/timer_1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O3 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


