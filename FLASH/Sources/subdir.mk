################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/ADCManager.c" \
"../Sources/DelayManager.c" \
"../Sources/DirectionManager.c" \
"../Sources/DistanceManager.c" \
"../Sources/MTIM.c" \
"../Sources/MessageManager.c" \
"../Sources/MotorManager.c" \
"../Sources/SCI.c" \
"../Sources/StringUtilis.c" \
"../Sources/TemperatureManager.c" \
"../Sources/TimersManager.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/ADCManager.c \
../Sources/DelayManager.c \
../Sources/DirectionManager.c \
../Sources/DistanceManager.c \
../Sources/MTIM.c \
../Sources/MessageManager.c \
../Sources/MotorManager.c \
../Sources/SCI.c \
../Sources/StringUtilis.c \
../Sources/TemperatureManager.c \
../Sources/TimersManager.c \
../Sources/main.c \

OBJS += \
./Sources/ADCManager_c.obj \
./Sources/DelayManager_c.obj \
./Sources/DirectionManager_c.obj \
./Sources/DistanceManager_c.obj \
./Sources/MTIM_c.obj \
./Sources/MessageManager_c.obj \
./Sources/MotorManager_c.obj \
./Sources/SCI_c.obj \
./Sources/StringUtilis_c.obj \
./Sources/TemperatureManager_c.obj \
./Sources/TimersManager_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/ADCManager_c.obj" \
"./Sources/DelayManager_c.obj" \
"./Sources/DirectionManager_c.obj" \
"./Sources/DistanceManager_c.obj" \
"./Sources/MTIM_c.obj" \
"./Sources/MessageManager_c.obj" \
"./Sources/MotorManager_c.obj" \
"./Sources/SCI_c.obj" \
"./Sources/StringUtilis_c.obj" \
"./Sources/TemperatureManager_c.obj" \
"./Sources/TimersManager_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/ADCManager_c.d \
./Sources/DelayManager_c.d \
./Sources/DirectionManager_c.d \
./Sources/DistanceManager_c.d \
./Sources/MTIM_c.d \
./Sources/MessageManager_c.d \
./Sources/MotorManager_c.d \
./Sources/SCI_c.d \
./Sources/StringUtilis_c.d \
./Sources/TemperatureManager_c.d \
./Sources/TimersManager_c.d \
./Sources/main_c.d \

C_DEPS_QUOTED += \
"./Sources/ADCManager_c.d" \
"./Sources/DelayManager_c.d" \
"./Sources/DirectionManager_c.d" \
"./Sources/DistanceManager_c.d" \
"./Sources/MTIM_c.d" \
"./Sources/MessageManager_c.d" \
"./Sources/MotorManager_c.d" \
"./Sources/SCI_c.d" \
"./Sources/StringUtilis_c.d" \
"./Sources/TemperatureManager_c.d" \
"./Sources/TimersManager_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/ADCManager_c.obj \
./Sources/DelayManager_c.obj \
./Sources/DirectionManager_c.obj \
./Sources/DistanceManager_c.obj \
./Sources/MTIM_c.obj \
./Sources/MessageManager_c.obj \
./Sources/MotorManager_c.obj \
./Sources/SCI_c.obj \
./Sources/StringUtilis_c.obj \
./Sources/TemperatureManager_c.obj \
./Sources/TimersManager_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/ADCManager_c.obj: ../Sources/ADCManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/ADCManager.args" -ObjN="Sources/ADCManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/DelayManager_c.obj: ../Sources/DelayManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/DelayManager.args" -ObjN="Sources/DelayManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/DirectionManager_c.obj: ../Sources/DirectionManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/DirectionManager.args" -ObjN="Sources/DirectionManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/DistanceManager_c.obj: ../Sources/DistanceManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/DistanceManager.args" -ObjN="Sources/DistanceManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/MTIM_c.obj: ../Sources/MTIM.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MTIM.args" -ObjN="Sources/MTIM_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/MessageManager_c.obj: ../Sources/MessageManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MessageManager.args" -ObjN="Sources/MessageManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/MotorManager_c.obj: ../Sources/MotorManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MotorManager.args" -ObjN="Sources/MotorManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/SCI_c.obj: ../Sources/SCI.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/SCI.args" -ObjN="Sources/SCI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/StringUtilis_c.obj: ../Sources/StringUtilis.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/StringUtilis.args" -ObjN="Sources/StringUtilis_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/TemperatureManager_c.obj: ../Sources/TemperatureManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/TemperatureManager.args" -ObjN="Sources/TemperatureManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/TimersManager_c.obj: ../Sources/TimersManager.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/TimersManager.args" -ObjN="Sources/TimersManager_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


