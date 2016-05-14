################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/containers/includes/abstracts/interfaces/node.cpp 

OBJS += \
./src/containers/includes/abstracts/interfaces/node.o 

CPP_DEPS += \
./src/containers/includes/abstracts/interfaces/node.d 


# Each subdirectory must supply rules for building sources it contributes
src/containers/includes/abstracts/interfaces/%.o: ../src/containers/includes/abstracts/interfaces/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


