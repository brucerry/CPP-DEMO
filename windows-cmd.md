Command for replacing spaces ' ' to underscores '_' for the filenames of .cpp in the directory
```
cmd /e:on /v:on /c "for %f in ("* *.cpp") do (set "n=%~nxf" & set "n=!n: =_!" & ren "%~ff" "!n!" )"
```
use "for /r %f" to loop through all the sub-folders
