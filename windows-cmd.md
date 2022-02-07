Windows Command Prompt (cmd)


Command for replacing spaces ' ' to underscores '_' for the filenames of .cpp in the directory
> cmd /e:on /v:on /c "for %f in ("* *.cpp") do (set "n=%~nxf" & set "n=!n: =_!" & ren "%~ff" "!n!" )"
  ^ Spawn a cmd instance
      ^ with extensions and delayed expansion enabled
                      ^ use "for /r %f" to loop through all the sub-folders in the directory if necessary
