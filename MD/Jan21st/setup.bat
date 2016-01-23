pushd C:\DD\pr\base
call setproj.bat UP
call SETUP32.BAT UP 
call cryptopp-lib-build-fetch set-jenkins-job
rem This isn't really needed, but the only harm is some extra time.
call cryptopp-lib-build-fetch get
cd C:\GitHub\Encrypto\MD\Jan21st\

