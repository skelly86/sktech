################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/containers/array.cpp \
../src/containers/btree.cpp \
../src/containers/chain.cpp \
../src/containers/itree.cpp \
../src/containers/rchain.cpp 

OBJS += \
./src/containers/array.o \
./src/containers/btree.o \
./src/containers/chain.o \
./src/containers/itree.o \
./src/containers/rchain.o 

CPP_DEPS += \
./src/containers/array.d \
./src/containers/btree.d \
./src/containers/chain.d \
./src/containers/itree.d \
./src/containers/rchain.d 


# Each subdirectory must supply rules for building sources it contributes
src/containers/%.o: ../src/containers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


