# STM32F103ZET6_CUBE_TEST

## 一、介绍

这是一个基于STM32F103ZET6芯片的开发板的测试项目，目的就是测试CubeMX+VSCode+HAL的开发环境是否正常且功能完备。

## 二、环境搭建

1. 安装CubeMX+VSCode并进行必要配置。（[参考视频](https://www.bilibili.com/video/BV1QfbpzGENy/?spm_id_from=333.337.search-card.all.click&vd_source=d8cb6312afe69434564a70a01af62c85)）
    > 完成这一步后，理应可以正常编译通过，并且可以通过STLink与JLink进行烧录与调试。如果使用DAPLink，请参考后续两步。

2. [下载OpenOCD](https://gnutoolchains.com/arm-eabi/openocd/)，然后解压到自己制定的安装目录，接着将bin目录添加到环境变量中，最后在项目的.vscode文件夹中创建task.json，并添加烧录任务：
    ```json
    {
        "version": "2.0.0",
        "tasks": [
            {
                "label": "flash-daplink", // 任务名称
                "type": "process",
                "command": "openocd",
                "args": [
                    "-f",
                    "interface/cmsis-dap.cfg",
                    "-f",
                    "target/stm32f1x.cfg", // 选择目标芯片
                    "-c",
                    "program build/Debug/stm32f103zet6_cube_test.elf verify reset exit" // 选择烧录文件
                ],
                "group": "build",
                "problemMatcher": []
            }
        ]
    }
    ```
    > 完成这一步后，在VSCode中按下快捷键`ctrl+shift+b`，弹出选项框后选择`flash-daplink`，等待烧录完成。如果需要进行全量调试，请参考下一步。

3. 给VSCode安装`Cortex-Debug`插件，打开插件设置，找到`cortex-debug.armToolchainPath`这个选项，将其设置为你当前项目的编译器路径。然后打开`.vscode/launch.json`文件，添加以下内容：
    ```json
    {
        "version": "0.2.0",
        "configurations": [
            {
                "name": "DAPLink Debug",
                "cwd": "${workspaceFolder}",
                "executable": "build/Debug/stm32f103zet6_cube_test.elf",
                "request": "launch",
                "type": "cortex-debug",
                "servertype": "openocd",
                "device": "STM32F103ZET6",
                "configFiles": [
                    "interface/cmsis-dap.cfg",
                    "target/stm32f1x.cfg"
                ],
                "svdFile": "STM32F103.svd",
                "runToEntryPoint": "main",
                "showDevDebugOutput": "none"
            }
        ]
    }
    ```
    > 完成这一步后，在VSCode中按下快捷键`ctrl+shift+d`，弹出选项框后选择`DAPLink Debug`，即可进行调试。