################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/containers/includes/abstracts/basic_chain.cpp \
../src/containers/includes/abstracts/basic_tree.cpp 

OBJS += \
./src/containers/includes/abstracts/basic_chain.o \
./src/containers/includes/abstracts/basic_tree.o 

CPP_DEPS += \
./src/containers/includes/abstracts/basic_chain.d \
./src/containers/includes/abstracts/basic_tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/containers/includes/abstracts/%.o: ../src/containers/includes/abstracts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


