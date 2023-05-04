# UE4 FPS Double Camera With Separate Field Of View

Render fps weapon model and scene with separate camera using different field of views.

Modern shooters use a double camera setup. One camera with a variable field of view is used for scene rendering and one camera with a fixed field of view is used to render just the weapon model and its animations.

Code files for [this tutorial on YouTube](https://youtu.be/rlnaDTkLjM0)

[More information](http://tigerpunchsportsclub.com/posts/shooting-practice/)

## Execute unit tests

```shell
C:\ue5\UE_5.1\Engine\Binaries\Win64\UnrealEditor.exe `
    'C:\ue5dev\ue4-fps-double-camera-separate-fov\FovTutorial.uproject' `
    -nosplash -nosound `
    -ExecCmds='Automation RunTests Defect; Quit' `
    -TestExit='Automation Test Queue Empty' `
    -ReportOutputPath='c:\work\tmp' `
    -Unattended -nopause -nullRHI -log ABSLOG='c:\work\tmp\log.txt'
```
