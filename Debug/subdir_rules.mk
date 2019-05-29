################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_CodeStartBranch.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_CpuTimers.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_CpuTimers.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_DefaultIsr.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_DefaultIsr.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_EPwm.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_EPwm.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_GlobalVariableDefs.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/source/F2806x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_PieCtrl.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_PieCtrl.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_PieVect.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_PieVect.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_SysCtrl.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_SysCtrl.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

F2806x_usDelay.obj: E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/source/F2806x_usDelay.asm $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla0 --float_support=fpu32 --vcu_support=vcu0 --include_path="D:/Software/CCS8/ccsv8/tools/compiler/ti-cgt-c2000_18.1.4.LTS/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_headers/include" --include_path="E:/Software/controlSUITE/device_support/f2806x/v150/F2806x_common/include" --include_path="E:/Software/controlSUITE/libs/math/IQmath/v160/include" --include_path="E:/Software/controlSUITE/libs/math/FPUfastRTS/V100/include" --define=_DEBUG --define=LARGE_MODEL -g --diag_suppress=10063 --diag_warning=225 --issue_remarks --verbose_diagnostics --quiet --output_all_syms --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


