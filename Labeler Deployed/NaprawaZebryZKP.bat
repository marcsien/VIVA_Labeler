@echo off
    net use  lpt1 /delete
    setlocal

    set quit=false
echo Wybierz drukarkê kodów:
echo (1) viva-etykiety
echo (2) viva-rampa
echo (3) viva-tubyliderzy
echo (4) viva-tubymagazyn
echo (5) viva-tubyprodukcja
    set /p InputChoices= (1,2,3,4,5)

    call :executeChoices %InputChoices%

    endlocal

goto :eof

:executeChoices 

    if [%1]==[] goto :eof

    call :Step%1
    shift
    goto :executeChoices    

goto :eof

:Step1
net use lpt1 \\9Z6TGM2\VIVA-ETYKIETY_ZM400 /persistent:yes 
goto :eof

:Step2
net use lpt1 \\JS9QB23\ZM400 /persistent:yes
goto :eof

:Step3
net use lpt1 \\PC0MD3HB\zebra /persistent:yes
goto :eof

:Step4
net use lpt1 \\viva-etykiety\tos /persistent:yes
goto :eof

:Step5
net use lpt1 \\CZC3393NNN\ZT410 /persistent:yes
goto :eof