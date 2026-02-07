################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SWITCH_CONTROLLED_LED
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SWITCH_CONTROLLED_LED.elf \

MAP_FILES += \
SWITCH_CONTROLLED_LED.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SWITCH_CONTROLLED_LED.list \

OBJCOPY_HEX += \
SWITCH_CONTROLLED_LED.hex \

OBJCOPY_BIN += \
SWITCH_CONTROLLED_LED.bin \


# All Target
all: main-build

# Main-build Target
main-build: SWITCH_CONTROLLED_LED.elf secondary-outputs

# Tool invocations
SWITCH_CONTROLLED_LED.elf SWITCH_CONTROLLED_LED.map: $(OBJS) $(USER_OBJS) C:\Users\piyush\STM32CubeIDE\workspace_2.0.0\BUTTON_CONTROLLED_LED\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "SWITCH_CONTROLLED_LED.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\piyush\STM32CubeIDE\workspace_2.0.0\BUTTON_CONTROLLED_LED\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SWITCH_CONTROLLED_LED.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SWITCH_CONTROLLED_LED.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SWITCH_CONTROLLED_LED.list"
	@echo 'Finished building: $@'
	@echo ' '

SWITCH_CONTROLLED_LED.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "SWITCH_CONTROLLED_LED.hex"
	@echo 'Finished building: $@'
	@echo ' '

SWITCH_CONTROLLED_LED.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "SWITCH_CONTROLLED_LED.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SWITCH_CONTROLLED_LED.bin SWITCH_CONTROLLED_LED.elf SWITCH_CONTROLLED_LED.hex SWITCH_CONTROLLED_LED.list SWITCH_CONTROLLED_LED.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
