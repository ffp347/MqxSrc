################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"$(COMMON1)/usb_framework.c" \

C_SRCS += \
$(COMMON1)/usb_framework.c \

OBJS += \
./USB\ Class\ Drivers/framework/usb_framework_c.obj \

OBJS_QUOTED += \
"./USB Class Drivers/framework/usb_framework_c.obj" \

C_DEPS += \
./USB\ Class\ Drivers/framework/usb_framework_c.d \

C_DEPS_QUOTED += \
"./USB Class Drivers/framework/usb_framework_c.d" \

OBJS_OS_FORMAT += \
./USB\ Class\ Drivers/framework/usb_framework_c.obj \


# Each subdirectory must supply rules for building sources it contributes
USB\ Class\ Drivers/framework/usb_framework_c.obj: $(COMMON1)/usb_framework.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Compiler'
	"$(ARM_ToolsDirEnv)/mwccarm" -gccinc @@"USB Class Drivers/framework/usb_framework.args" -o "USB Class Drivers/framework/usb_framework_c.obj" -c "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

USB\ Class\ Drivers/framework/usb_framework_c.d: $(COMMON1)/usb_framework.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


