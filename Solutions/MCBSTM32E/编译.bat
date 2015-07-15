@echo off
:: 设置一些参数
::set x_flavor=debug
set x_flavor=release
set x_memory=flash
set x_root=..\..\

:: 先尝试取得当前目录名，作为方案名

for %%i in ("%cd%") do set x_name=%%~ni

title 编译MF方案[%x_name%][%x_flavor%][%x_memory%]

pushd %x_root%
call setenv_MDK.cmd
popd

if exist msbuild.log del msbuild.log /f/q

call msbuild dotnetmf.proj /t:build /p:flavor=%x_flavor%;memory=%x_memory% /maxcpucount /noLogo /v:minimal /fileLogger /flp:Verbosity=normal
:: > build.log

IF %errorlevel% == 0 (
	:: 绿色显示成功
	echo *******************************
	echo 编译成功
	echo *******************************
) ELSE (
	:: 解决未能复制的错误
	set x_buildout_server=%BUILD_ROOT_BASE%\Public\%x_flavor%\Server
	set x_task_name=Microsoft.SPOT.Tasks.Internal
	copy /y %x_buildout_server%\obj\%x_task_name%\__COMMON\%x_task_name%.dll %x_buildout_server%\dll\%x_task_name%.dll
	
	echo *******************************
	echo 编译出错，请到msbuild.log中通过搜索error关键字检查详细错误信息！
	echo 有可能重新编译后错误会消失，也有可能删除输出目录后可以解决错误！
	echo 
	pause
	GOTO :EOF
)

:copybin
:: 把生成的文件复制出来
set x_buildout=%BUILD_ROOT_BASE%\THUMB2\%COMPILER_TOOL_VERSION%\le\%x_memory%\%x_flavor%\%x_name%\bin
if not exist %x_buildout% set x_buildout=%BUILD_ROOT_BASE%\THUMB2FP\%COMPILER_TOOL_VERSION%\le\%x_memory%\%x_flavor%\%x_name%\bin
set x_bindir=%x_root%..\MFBin\%x_name%

if not exist %x_bindir% md %x_bindir%
:: 复制TinyBooter.bin
del %x_buildout%\*.axfdump /f/q
copy %x_buildout%\*.bin %x_bindir%\ /y
copy %x_buildout%\*.axf %x_bindir%\ /y

del %x_buildout%\*.bin /f/q
del %x_buildout%\*.axf /f/q

:: 复制ER_FLASH和ER_CONFIG
set x_buildout=%x_buildout%\tinyclr.bin
copy %x_buildout%\*.* %x_bindir%\ /y
copy %x_bindir%\ER_FLASH %x_bindir%\TinyCLR.bin /y

echo 输出已复制到 %x_bindir%\

echo 
pause

del %x_bindir%\ER_FLASH /f/q
